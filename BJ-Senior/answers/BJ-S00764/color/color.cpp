#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t,n,a[200010],last[200010],wei[1000010];
long long dp[110][110][110];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,-0x3f,sizeof(dp));
        memset(wei,0,sizeof(wei));
        scanf("%d",&n);
        for (int i = 1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            last[i] = wei[a[i]];
            wei[a[i]] = i;
        }
        dp[0][0][0] = 0;
        for (int i = 1;i<=n;i++)
        {
            //ran1
            for (int j = 0;j<i;j++)//2zuihou weizhi
                for (int k = 0;k<i;k++)//yuan1 zuihou weizhi
                {
                    if(a[i] == a[k])
                        dp[i][i][j] = max(dp[i][i][j],dp[i-1][k][j]+a[i]);
                    else dp[i][i][j] = max(dp[i][i][j],dp[i-1][k][j]);
                }
            //ran2
            for (int j = 0;j<i;j++)//1zuihou weizhi
                for (int k = 0;k<i;k++)//yuan2 zuihou weizhi
                {
                    if(a[i] == a[k])
                        dp[i][j][i] = max(dp[i][j][i],dp[i-1][j][k]+a[i]);
                    else dp[i][j][i] = max(dp[i][j][i],dp[i-1][j][k]);
                }
        }
        //for (int i = 1;i<=n;i++)
        //{
        //    printf("%d: ",i);
        //    for (int j = 0;j<i;j++)
        //        printf("%d %d %d  ",i,j,dp[i][i][j]);
        //    for (int j = 0;j<i;j++)
        //        printf("%d %d %d  ",j,i,dp[i][j][i]);
        //    printf("\n");
        //}

        long long ans = 0;
        for (int i = 0;i<n;i++)
            ans = max(ans,dp[n][n][i]);
        for (int i = 0;i<n;i++)
            ans = max(ans,dp[n][i][n]);
        printf("%lld\n",ans);
    }

    return 0;
}
