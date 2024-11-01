#include<bits/stdc++.h>
using namespace std;
int t,n,a[20],vis[20],ans;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> t;
    while(t --)
    {
        cin >> n;
        for(int i=1;i<=n;i++)   vis[i] = 0;
        for(int i=1;i<=n;i++)   cin >> a[i];
        ans = 0;
        for(int i=0;i<(1<<n);i++)
        {
            for(int i=1;i<=n;i++)   vis[i] = 0;
            int x = i,id = 1,sum = 0;
            while(x)
            {
                if(x & 1)   vis[id] = 1;
                id ++;
                x >>= 1;
            }
            for(int j=2;j<=n;j++)
            {
                for(int k=j-1;k>=1;k--)
                {
                    if(vis[k] == vis[j])
                    {
                        if(a[k] == a[j])    sum += a[j];
                        break;
                    }
                }
            }
            ans = max(ans,sum);
        }
        cout << ans << '\n';
    }
    return 0;
}

