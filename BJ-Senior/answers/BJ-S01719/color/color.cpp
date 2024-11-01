#include<bits/stdc++.h>
using namespace std;
int a[200100],dp[200100],h[200100];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int n,t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(h,0,sizeof(h));
		int ans=-1e9;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			dp[i]=(h[a[i]]>0)*a[i]+dp[i-1];
			h[a[i]]++;
			ans=max(ans,dp[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}