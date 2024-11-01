#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5050;
int T,n,dp[N][N],a[N];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int i,j;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		int ans=0;
		for(i=1;i<=n;i++){
			int mx=0;
			for(j=1;j<i;j++){
				dp[i][j]=max(dp[i][j],dp[i-1][j]+(a[i]==a[i-1])*a[i]);
			}
			mx=0;
			for(j=1;j<i-1;j++){
				mx=max(mx,dp[j][i-1]+(a[i]==a[j])*a[i]);
			}
			dp[i][i-1]=max(dp[i][i-1],mx);
			for(j=1;j<i;j++){
				dp[j][i]=max(dp[j][i],dp[j][i-1]+(a[i]==a[i-1])*a[i]);
			}
			mx=0;
			for(j=1;j<i-1;j++){
				mx=max(mx,dp[i-1][j]+(a[i]==a[j])*a[i]);
			}
			dp[i-1][i]=max(dp[i-1][i],mx);
		}
		for(i=1;i<n;i++)
			ans=max(ans,max(dp[n][i],dp[i][n]));
		printf("%d\n",ans);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				dp[i][j]=0;
	}
	return 0;
}
