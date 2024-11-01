#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=2e5+5;
ll T;
ll n,a[MAXN];
namespace pts20{
	ll id[20];
	ll dfs(ll u,ll pt){
		if(u==n+1){
			ll val=0;
			for(int i=1;i<=n;++i){
				for(int j=i-1;j>=1;--j){
					if(id[j]==id[i]){
						val+=(a[j]==a[i])*a[i];
						break;
					}
				}
			}
			if(pt&&val==pt){
				for(int i=1;i<=n;++i){
					cout<<id[i]<<" ";
				}
				cout<<endl;
			}
			return val;
		}
		id[u]=0;
		ll val=dfs(u+1,pt);
		id[u]=1;
		val=max(val,dfs(u+1,pt));
		return val;
	};
	void Do(){
		ll ans=dfs(1,0);
		cout<<ans<<endl;
		//dfs(1,ans);
	};
}
namespace ptsbl{
	ll dp[2005][2005],ma[MAXN],lst[MAXN],p[1000005];
	void Do(ll testT){
		memset(dp,0,sizeof(dp));
		memset(ma,0,sizeof(ma));
		for(int i=1;i<=n;++i){
			lst[i]=p[a[i]];
			//cout<<"lst"<<lst[i]<<endl;
			p[a[i]]=i;
		}
		for(int i=1;i<=n;++i){
			p[a[i]]=0;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<i;++j){
				if(j==i-1){
					ll val=0;
					dp[i][j]=dp[j-1][ma[j-1]]+(a[j-1]==a[i])*a[i];
					dp[i][j]=max(dp[i][j],dp[j-1][lst[j]]+(a[j-1]==a[i])*a[i]+(a[lst[j]]==a[j])*a[j]);	
					//~ if(T==testT){
			//~ cout<<i<<" "<<j<<" "<<ma[j-1]<<" "<<dp[j-1][lst[j]]<<" "<<lst[j-1]<<" "<<(a[lst[j]]==a[j])*a[j]<<endl;
					//~ }
					for(int k=j-1;k>=1;--k){
						val+=(a[k+1]==a[k])*a[k];
						dp[i][j]=max(dp[i][j],val+dp[k-1][ma[k-1]]+(a[k-1]==a[i])*a[i]+(a[k]==a[ma[k-1]])*a[k]);
						dp[i][j]=max(dp[i][j],val+dp[k-1][lst[k]]+(a[k-1]==a[i])*a[i]+(a[k]==a[lst[k]])*a[k]);
						//~ if(T==testT){
							//~ cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
						//~ }
					}
					ma[i]=j;
				}else{
					dp[i][j]=dp[i-1][j]+(a[i]==a[i-1])*a[i];
					if(dp[i][ma[i]]<dp[i][j]){
						ma[i]=j;
					}
				}
				//~ if(T==testT){
					//~ cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
				//~ }
			}
		}
		cout<<dp[n][ma[n]]<<endl;
	};
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		if(n<=15){
			pts20::Do();
			continue;
		}
		if(n<=2000){
			ptsbl::Do(1);
		}
	}
	return 0;
}

