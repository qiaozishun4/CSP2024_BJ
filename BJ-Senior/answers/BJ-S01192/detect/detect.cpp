#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,L,V;
        cin >> n >> m >> L >> V;
        int d[1005]={},v[1005]={},a[1005]={};
        for(int i=1;i<=n;i++)
        {
            cin >> d[i] >> v[i] >> a[i];
        }
        int p[100005]={};
        for(int i=1;i<=m;i++)
        {
            cin >> p[i];
        }
        int ans=0;
        int c[100005]={};
        for(int i=1;i<=n;i++)
        {
            int jc=1;
            while(d[i]<L)
            {
                if(p[jc]>=d[i]&&p[jc]<=(d[i]+v[i]))
                {
                    if(v[i]>V)
                    {
                        c[jc]++;
                        ans++;
                        break;
                    }
                    else
                    {
                        jc++;
                    }
                }
                d[i]+=v[i];
                v[i]+=a[i];
                if(v[i]<=0) break;
            }
        }
        cout << ans << " ";
        int sum=0;
        for(int i=1;i<=m;i++)
        {
            if(c[i]==0)
            {
                sum++;
            }
        }
        cout << sum;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
