#include<bits/stdc++.h>
using namespace std;
int T,n,a[10001],dp[2002][2002],ans,s1[2002],s2[2002];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		memset(dp,0xf0,sizeof(dp));
		memset(s1,0xf0,sizeof(s1));
		memset(s2,0xf0,sizeof(s2));
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dp[0][0]=0;
		s1[0]=s2[0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=2000;j++){
				if(j==a[i]){
					dp[a[i]][a[i]]=max(dp[a[i]][a[i]]+a[i],max(s1[a[i]],s2[a[i]]));
				}
				else{
					dp[j][a[i]]=max(s1[j],dp[j][a[i]]+a[i]);
					dp[a[i]][j]=max(s2[j],dp[a[i]][j]+a[i]);
				}
				ans=max(dp[a[i]][j],max(ans,dp[j][a[i]]));
				s1[a[i]]=max(dp[j][a[i]],s1[a[i]]);
				s1[j]=max(dp[a[i]][j],s1[j]);
				s2[a[i]]=max(dp[a[i]][j],s2[a[i]]);
				s2[j]=max(dp[j][a[i]],s2[j]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
