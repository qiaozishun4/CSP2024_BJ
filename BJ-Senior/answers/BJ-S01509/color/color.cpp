#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,a[N];
int dp[2005][2005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i-1;j++)
            {
                dp[i][j]=dp[i-1][j]+(a[i-1]==a[i]?a[i-1]:0);
                dp[i][i-1]=max(dp[i][i-1],dp[i-1][j]+(a[j]==a[i]?a[j]:0));
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,dp[n][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
