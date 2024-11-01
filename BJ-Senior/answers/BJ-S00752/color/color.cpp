#include<bits/stdc++.h>
using namespace std;
int a[200005],pre[200005],l[1000005];
long long f[200005],dp[200005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=1e6;i++)
            l[i]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            pre[i]=l[a[i]];
            l[a[i]]=i;
            f[i]=f[i-1];
            if(a[i]==a[i-1])
                f[i]+=a[i];
        }
        for(int i=1;i<=n;i++)
            dp[i]=-1e9;
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i-1];
            if(pre[i])
            {
                dp[i]=max(dp[i],dp[pre[i]]+f[i-1]-f[pre[i]]+a[i]);
                dp[i-1]=max(dp[i-1],dp[pre[i]]+f[i-1]-f[pre[i]]+a[i]);
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
