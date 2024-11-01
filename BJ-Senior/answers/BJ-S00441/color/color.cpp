#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005][2];//表示前i位有j个红色 有i-j个蓝色；这一位0为红色 1为蓝色 
int a[100005],t[1000005],wz[1000005];
void solve(){
	int n;
	cin>>n;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j][0]=0,dp[i][j][1]=0;
		}
	}
	for(int i=1;i<=1000000;i++) t[i]=0,wz[i]=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		wz[i]=t[a[i]];
		t[a[i]]=i;
		//cout<<wz[i]<<' ';
	}
	//cout<<endl;
	for(int i=2;i<=n;i++){
		int p=wz[i];
		if(p==0){
			for(int j=0;j<=i;j++){
				dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]);
				dp[i][j][1]=max(dp[i-1][j][0],dp[i-1][j][1]);
				//cout<<dp[i][j][0]<<' '<<dp[i][j][1]<<" ；";
			}
			//cout<<endl;
			continue;
		}
		for(int j=0;j<=i;j++){
			if(j>0) dp[i][j][0]=max(max(dp[i-1][j-1][0],dp[i-1][j][1])+a[i],dp[p][j-1][0]+a[i]);
			dp[i][j][1]=max(max(dp[i-1][j-1][0],dp[i-1][j][1])+a[i],dp[p][j-(i-p-1)][1]+a[i]);
			//cout<<dp[i][j][0]<<' '<<dp[i][j][1]<<" ；";
		}
		//cout<<endl;
	}
	int ans=0;
	for(int j=0;j<=n;j++){
		ans=max(ans,max(dp[n][j][0],dp[n][j][1]));
	}
	cout<<ans<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
}
