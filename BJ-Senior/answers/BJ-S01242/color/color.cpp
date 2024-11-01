#include<bits/stdc++.h>
using namespace std;
const int MAXN=2005;
int T;
int dp[MAXN][MAXN],a[MAXN],n;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		memset(dp,0,sizeof(dp));
		for(int i=2;i<=n;i++){
			//1 同色
			for(int j=0;j<i-1;j++){
				dp[i][j]=max(dp[i][j],dp[i-1][j]+(a[i]==a[i-1]?a[i]:0));
			}
			//2不同色
			for(int j=0;j<i-1;j++)dp[i][i-1]=max(dp[i][i-1],dp[i-1][j]+(a[i]==a[j]?a[i]:0));
		}
		int ans=0;
		for(int i=0;i<n;i++)ans=max(ans,dp[n][i]);
		cout<<ans<<endl;
	}
	return 0;
}
