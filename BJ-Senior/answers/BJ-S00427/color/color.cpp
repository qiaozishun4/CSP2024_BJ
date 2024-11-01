#include<iostream>
using namespace std;
int T;
int n;
int a[2001];
int dp[2001][2001];
void pro(){
	scanf("%d",&n);
	if(n>2000)return;
	for(int i = 0;i<=n;i++){
		for(int j = 0;j<=n;j++){
			dp[i][j] = 0;
		}
	}
	for(int i = 1;i<=n;i++){
		scanf("%d",a+i);

	}

	for(int i = 1;i<=n;i++){
		//red-blue

		//red-after-red
		for(int j = 0;j<i;j++)dp[i][j] = max(dp[i][j],dp[i-1][j]+(a[i]==a[i-1])*a[i]);
		//rab
		for(int j = 0;j<i-1;j++) dp[i][i-1] = max(dp[i][i-1],dp[j][i-1]+(a[i]==a[j])*a[i]);
		//bab
		for(int j = 0;j<i;j++) dp[j][i] = max(dp[j][i],dp[j][i-1]+(a[i]==a[i-1])*a[i]);
		//bar
		for(int j = 0;j<i-1;j++) dp[i-1][i] = max(dp[i-1][i],dp[i-1][j]+(a[i]==a[j])*a[i]);


	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(i!=j)ans = max(ans,dp[i][j]);
		}
	}
	cout << ans << endl;
	return;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	for(int i = 1;i<=T;i++){
		pro();
	}
	return 0;
}