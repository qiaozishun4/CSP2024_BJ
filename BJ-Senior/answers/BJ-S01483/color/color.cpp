#include<bits/stdc++.h>
#define int long long
#define N 2010
using namespace std;
int T,n,a[N],dp[N][N][2];
signed main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        if(n>2000)continue;
        dp[1][0][0]=dp[1][0][1]=0;
        for(int i=2;i<=n;i++)
        {
            dp[i][i-1][0]=dp[i][i-1][1]=0;
            for(int j=0;j<i-1;j++)
            {
                dp[i][j][0]=(a[i-1]==a[i]?a[i]:0)+dp[i-1][j][0];
                dp[i][j][1]=(a[i-1]==a[i]?a[i]:0)+dp[i-1][j][1];
                dp[i][i-1][0]=max(dp[i][i-1][0],dp[i-1][j][1]+(a[i]==a[j]?a[i]:0));
                dp[i][i-1][1]=max(dp[i][i-1][1],dp[i-1][j][0]+(a[i]==a[j]?a[i]:0));
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,max(dp[n][i][0],dp[n][i][1]));
        }
        printf("%lld\n",ans);
    }
    return 0;
}