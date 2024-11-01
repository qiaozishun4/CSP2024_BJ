#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
LL a[200010];
LL f[200010];
LL s[200010][22];
LL dp[200010][2];
LL t[1000010];
void init(){
	for(int j=1;j<20;j++){
		for(int i=1;i<=n;i++){
			LL k=(1<<(j-1));
			s[i][j]=s[i][j-1];if(i+k<=n) s[i][j]+=s[i+k][j-1];
			if(i+k<=n&&a[i+k]==a[i+k-1]) s[i][j]+=a[i+k];
		}
	}
}
LL query(int l,int r){
	if(l>=r) return 0;
	LL tmp=0,lst=0;
	for(int i=19;i>=0;i--){
		if(l+(1<<i)-1<=r){
			tmp+=s[l][i];
			if(lst==a[l]) tmp+=lst;
			l+=(1<<i);lst=a[l-1];
		}
	}return tmp;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;cin>>T;while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) dp[i][0]=dp[i][1]=f[i]=0;
		init();
		if(n<=2000){
			for(int i=1;i<=n;i++){
				dp[i][0]=max(dp[i-1][0]+(a[i]==a[i-1])*a[i],dp[i-1][1]);
				dp[i][1]=max(dp[i-1][1]+(a[i]==a[i-1])*a[i],dp[i-1][0]);
				for(int j=1;j<i;j++){
					if(a[i]==a[j-1]){
						dp[i][0]=max(dp[i][0],dp[j][1]+a[i]+query(j,i-1));
						dp[i][1]=max(dp[i][1],dp[j][0]+a[i]+query(j,i-1));
					}
				}//cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
			}
			cout<<max(dp[n][0],dp[n][1])<<"\n";
			continue;
		}
		for(int i=0;i<=1e6;i++) t[i]=0;
		for(int i=1;i<=n;i++) f[i]=t[a[i]],t[a[i]]=i;
		for(int i=1;i<=n;i++){
			dp[i][0]=max(dp[i-1][0]+(a[i]==a[i-1])*a[i],dp[i-1][1]);
			dp[i][1]=max(dp[i-1][1]+(a[i]==a[i-1])*a[i],dp[i-1][0]);
			if(!f[i]||f[i]==i-1) continue;
			int j=f[i]+1;
			dp[i][0]=max(dp[i][0],dp[j][1]+a[i]+query(j,i-1));
			dp[i][1]=max(dp[i][1],dp[j][0]+a[i]+query(j,i-1));
		}
		cout<<max(dp[n][0],dp[n][1])<<"\n";
	}
	return 0;
}
