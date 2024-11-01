#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
const int N=1e5+1;
int dp[N];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=0;j<=9;j++){
				if(i-a[j]==0||i-a[j]>1){
					if(dp[i]!=0) dp[i]=min(dp[i],dp[i-a[j]]*10+j);
					else dp[i]=dp[i-a[j]]*10+j;
				}
			}
		}
		if(dp[n]==0) cout<<-1<<endl;
		else cout<<dp[n]<<endl;
	}
	return 0;
}