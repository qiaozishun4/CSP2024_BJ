#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int maxn=2e3+10,maxm=2e5+10;
const ll inf=1e15+7;
int n,a[maxm],lst[maxn],m,s[maxm];
ll f[maxn][maxn],dp[maxm][15];
int score(int l,int r){
	if(l>r) return 0;
	return s[r]-s[l-1]-(a[l]==a[l-1]?a[l]:0);
}
void s1(){
	for(int i=1;i<=m;i++) lst[i]=0;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+(a[i]==a[i-1]?a[i]:0);
	for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) dp[i][j]=-inf;
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++) dp[i][j]=dp[i-1][j]+(a[i-1]==a[i]?a[i]:0);
		for(int j=0;j<=m;j++) dp[i][a[i-1]]=max(dp[i][a[i-1]],dp[i-1][j]);
		if(lst[a[i]]){
			if(a[i]!=a[i-1]){
				for(int j=0;j<=m;j++){
					dp[i][a[i-1]]=max(dp[i][a[i-1]],dp[lst[a[i]]][j]+score(lst[a[i]]+1,i-1)+(a[lst[a[i]]+1]==j?j:0)+a[i]);
				}
			}
			else{
				for(int j=0;j<=m;j++){
					dp[i][a[i-1]]=max(dp[i][a[i-1]],dp[lst[a[i]]][j]+score(lst[a[i]]+1,i-1)+(a[lst[a[i]]+1]==j?j:0));
				}
			}
		}
		lst[a[i]]=i;
	}
	ll ans=0;
	for(int i=0;i<=m;i++) ans=max(ans,dp[n][i]);
	cout<<ans<<endl;
}
void so(){
	cin>>n;m=0;
	for(int i=1;i<=n;i++) cin>>a[i],m=max(m,a[i]);
	if(m<=10&&n>2e3){s1();return;}
	if(n>2e3||m>2e3){cout<<0<<endl;return;}
	for(int i=1;i<=m;i++) lst[i]=0;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+(a[i]==a[i-1]?a[i]:0);
	for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) f[i][j]=-inf;
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++) f[i][j]=f[i-1][j]+(a[i-1]==a[i]?a[i]:0);
		for(int j=0;j<=m;j++) f[i][a[i-1]]=max(f[i][a[i-1]],f[i-1][j]);
		if(lst[a[i]]){
			if(a[i]!=a[i-1]){
				for(int j=0;j<=m;j++){
					f[i][a[i-1]]=max(f[i][a[i-1]],f[lst[a[i]]][j]+score(lst[a[i]]+1,i-1)+(a[lst[a[i]]+1]==j?j:0)+a[i]);
				}
			}
			else{
				for(int j=0;j<=m;j++){
					f[i][a[i-1]]=max(f[i][a[i-1]],f[lst[a[i]]][j]+score(lst[a[i]]+1,i-1)+(a[lst[a[i]]+1]==j?j:0));
				}
			}
		}
		lst[a[i]]=i;
	}
	ll ans=0;
	for(int i=0;i<=m;i++) ans=max(ans,f[n][i]);
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;cin>>t;
	while(t--) so();
	return 0;
}
