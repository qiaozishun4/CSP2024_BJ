
#include <bits/stdc++.h>
#define N int(1e5+10)
#define INF ((ll)1e18)
using namespace std;
typedef long long ll;
ll d[N],v[N],a[N],p[N],T,n,m,L,V,ans,maxn=-INF,s;
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		memset(d,0,sizeof d);
		memset(v,0,sizeof v);
		memset(a,0,sizeof a);
		memset(p,0,sizeof p);
		maxn=-1e18;
		ans=s=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;++i) cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;++i) cin>>p[i];
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(p[j]>d[i]&&v[i]>V){
					ans++;
					maxn=max(maxn,d[i]);
					break;
				}
		cout<<ans<<' ';
		for(int i=1;i<=m;++i){
			if(p[i]<maxn) s++;
			else break;
		}
		cout<<s<<'\n';
	}
	return 0;
}