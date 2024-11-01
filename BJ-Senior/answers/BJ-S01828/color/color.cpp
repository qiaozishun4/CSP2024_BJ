
#include <bits/stdc++.h>
#define N int(2e5+10)
using namespace std;
typedef long long ll;
ll a[N],r[N],T,n,ans=-1e18;
inline void dfs(ll u){
	if(u==n+1){
		ll t=0;
		for(int i=1;i<=n;++i)
			for(int j=i-1;j>=1;--j)
				if(r[i]==r[j]){
					if(a[i]==a[j]) t+=a[i];
					else t+=0;
				}else t+=0;
		ans=max(ans,t);
		return ;
	}
	r[u]=1;
	dfs(u+1);
	r[u]=2;
	dfs(u+1);
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof a);
		memset(r,0,sizeof r);
		ans=-1e18;
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i];
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}