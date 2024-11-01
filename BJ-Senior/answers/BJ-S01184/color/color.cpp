#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010];
int dp[200010][2];
int sum[200010];
int ax[1000010];
signed main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    int t; cin>>t; while(t--)
    {
        cin>>n;
        for(int i=1; i<=n; ++i) cin>>a[i];
        for(int i=1; i<=n; ++i) sum[i]=sum[i-1]+(i!=1 && a[i]==a[i-1]?a[i]:0);
        int allax=-1e18;
        memset(ax,-0x3f,sizeof(ax));
        for(int i=1; i<=n; ++i)
        {
            dp[i][0]=dp[i][1]=sum[i-1];
            if(i!=1) dp[i][0]=max(dp[i][0],dp[i-1][0]+(a[i]==a[i-1]?a[i]:0));
            if(i-2>=1)
            {
                allax=max(allax,-sum[i-2+1]+dp[i-2+1][1]);
                ax[a[i-2]]=max(ax[a[i-2]],-sum[i-2+1]+dp[i-2+1][1]);
            }
            int ans=max(allax+sum[i-1],ax[a[i]]+sum[i-1]+a[i]);
            dp[i][0]=max(dp[i][0],ans),dp[i][1]=max(dp[i][1],ans);
            /*
            for(int j=i-2; j>=1; --j)
            {
                int ans=sum[i-1]-sum[j+1]+dp[j+1][1]+(a[i]==a[j]?a[i]:0);
                dp[i][0]=max(dp[i][0],ans),dp[i][1]=max(dp[i][1],ans);
            }
            */
        }
        cout<<dp[n][0]<<'\n';
    }
    return 0;
}
