#include<bits/stdc++.h>
using namespace std;
const int N=2e3+7;
int t,n,ans,arr[N],dp[N][N];
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	for(scanf("%d",&t);t;t--)
	{
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			dp[i][i]=0,scanf("%d",&arr[i]);
		for(int i=2;i<=n;i++)
		{
			for(int j=2;j<i;j++)
				dp[i][i]=max(dp[i][i],dp[j][i-1]+(arr[j-1]==arr[i])*arr[i]);
			for(int j=1;j<i;j++)
				dp[j][i]=dp[j][i-1]+(arr[i]==arr[i-1])*arr[i];
		}
		for(int i=1;i<=n;i++)
			ans=max(ans,dp[i][n]);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}