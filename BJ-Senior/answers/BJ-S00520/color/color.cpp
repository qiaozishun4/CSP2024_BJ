#include<bits/stdc++.h>
using namespace std;
int n,a[100005],dp[20005],t,s[100005];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dp[1]=0;
		s[1]=0;
		for(int i=2;i<=n;i++){
			bool blg=0;
			for(int j=1;j<i;j++){
				if(a[j]==a[i]){
					s[i]=j;
					blg=1;
					break;
				}
			}
			if(blg==0) s[i]=0;
		}
		for(int i=2;i<=n;i++) dp[i]=max(dp[i-1],dp[s[i]]+a[s[i]]);
		cout<<dp[n]<<endl;
		memset(dp,0,sizeof(dp));
	}
	return 0;
}
