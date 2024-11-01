#include<bits/stdc++.h>
using namespace std;
int sum[1500000],a[100];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;cin>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
        int pb=0,pr=0,n;cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<(1<<n);i++)//0 blue     1 red
        {
            pb=0,pr=0;
            for(int j=1;j<=n;j++)
            {
                if((i>>j)&1)
                {
                    if(a[pr]==a[j])
                    sum[i]+=a[j];
                    pr=j;
                }
                else
                {
                    if(a[pb]==a[j])
                    sum[i]+=a[j];
                    pb=j;
                }
            }
        }
        int ans=0;
        for(int i=0;i<(1<<n);i++)
        {
            ans=max(ans,sum[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}