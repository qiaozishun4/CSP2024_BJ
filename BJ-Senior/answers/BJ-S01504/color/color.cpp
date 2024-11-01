#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int dp[N][2][N],a[N];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i-1;j++)
			{
				dp[i+1][0][j]=max(dp[i+1][0][j],dp[i][0][j]+(a[i]==a[i+1])*a[i]);
				dp[i+1][1][i]=max(dp[i+1][1][i],dp[i][0][j]+(a[j]==a[i+1])*a[j]);
			}
			for(int j=1;j<=i-1;j++)
			{
				dp[i+1][1][j]=max(dp[i+1][1][j],dp[i][1][j]+(a[i]==a[i+1])*a[i]);
				dp[i+1][0][i]=max(dp[i+1][0][i],dp[i][1][j]+(a[j]==a[i+1])*a[j]);
			}
		}
		int ans=0;
		for(int i=0;i<=1;i++)
		{
			for(int j=1;j<=n;j++)
			{
				ans=max(ans,dp[n][i][j]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}