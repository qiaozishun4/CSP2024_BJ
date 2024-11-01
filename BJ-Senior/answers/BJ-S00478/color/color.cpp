#include<bits/stdc++.h>

using namespace std;

int T;
int n;
int a[200005];
long long ans;
long long dp[2005][2005][2];

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		ans=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=i;j++)
			{
				if (i==j)
				{
					dp[i][j][0]=dp[i][j][1]=0;
					for (int k=1;k<i;k++)
					{
						dp[i][j][0]=max(dp[i][j][0],dp[i-1][k][1]+(a[i]==a[k-1])*a[i]);
						dp[i][j][1]=max(dp[i][j][1],dp[i-1][k][0]+(a[i]==a[k-1])*a[i]);
					}
				}
				else
				{
					dp[i][j][0]=dp[i-1][j][0]+(a[i]==a[i-1])*a[i];
					dp[i][j][1]=dp[i-1][j][1]+(a[i]==a[i-1])*a[i];
				}
				ans=max(ans,max(dp[i][j][0],dp[i][j][1]));
				// printf("dp[%d][%d]=%lld,%lld\n",i,j,dp[i][j][0],dp[i][j][1]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}