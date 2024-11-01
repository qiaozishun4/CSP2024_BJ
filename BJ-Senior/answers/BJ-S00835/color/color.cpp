#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define ll __int128
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
int T,n,a[200010],dp[1000010];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	fre("color");
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		memset(dp,-0x3f,sizeof(dp));
		int mx=0,tg=0;
		for(int i=1;i<=n;++i){
			if(a[i]==a[i-1])tg+=a[i];
			int tmp2=dp[mx],tmp3=dp[a[i]];
			dp[a[i]]=max(dp[a[i]],0ll-tg);
			if(dp[a[i]]>dp[mx])mx=a[i];
			dp[a[i-1]]=max(dp[a[i-1]],max(tmp2,tmp3+a[i])+(a[i]==a[i-1]?-a[i]:0));
			if(dp[a[i-1]]>dp[mx])mx=a[i-1];
		}
		int ans=0;
		for(int i=1;i<=1e6;++i)ans=max(ans,dp[i]+tg);
		cout<<ans<<'\n';
	}
	return 0;
}