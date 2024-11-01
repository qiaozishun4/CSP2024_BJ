#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> t;
    while(t--)
    {
        long long n,a[100005],ans=0;
        cin >> n;
        for (int i=1;i<=n;i++)
        {
            cin >>a[i];
        }
        for (int i=0;i<=(1<<n)-1;i++)
        {
            long long s=i,k=0,b[100005],sum=0;
            while(s)
            {
                b[++k]=s%2;
                s/=2;
            }
            for (int j=1;j<=n;j++)
            {
                int g=j;
                while(g>0)
                {
                    g--;
                    if (b[g]==b[j])
                    {
                        if (a[g]==a[j])
                            sum+=a[j];
                        break;
                    }
                }

            }
            ans=max(ans,sum);
        }
        cout << ans << "\n";
    }
    return 0;
}

