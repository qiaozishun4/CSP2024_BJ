#include <bits/stdc++.h>
using namespace std;
#define LL long long

#define M 107
#define m 100

int dp[M][M],lmax[M],cmax[M],tmp[M],pmt[M];

inline int solve(){
	for(int i=1;i<=m;i++){
		lmax[i]=cmax[i]=dp[0][i]=dp[i][0]=-1;
		for(int j=1;j<=m;j++) dp[i][j]=-1;
	}
	int n,Ans=0;
	cin>>n;
	while(n--){
		int a;
		cin>>a;
		for(int i=0;i<=m;i++){
			tmp[i]=dp[a][i],pmt[i]=dp[i][a];
			for(int j=0;j<=m;j++){
				if(~dp[j][i]) tmp[i]=max(tmp[i],dp[j][i]+(j==a?a:0));
				if(~dp[i][j]) pmt[i]=max(pmt[i],dp[i][j]+(j==a?a:0));
			}
		}
		for(int i=0;i<=m;i++)
			if(i!=a) dp[a][i]=tmp[i],dp[i][a]=pmt[i];
			else dp[a][a]=max(tmp[a],pmt[a]);
		if(!n) for(int i=0;i<=m;i++) Ans=max(Ans,max(dp[a][i],dp[i][a]));
		
		/*for(int i=0;i<=5;i++){
			for(int j=0;j<=5;j++) cout<<dp[i][j]<<' ';
			cout<<'\n';
		}
		cout<<'\n';*/
	}
	
	cout<<Ans<<'\n';
	return 0;
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr),cout.tie(nullptr);

	int T;
	cin>>T;
	while(T--) solve();

    return 0;
}
