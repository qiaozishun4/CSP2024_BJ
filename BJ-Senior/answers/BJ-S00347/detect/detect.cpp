#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e5+5;
ll T;
ll n,m,L,V;
long double nd(ll d,ll v,ll a){
	double D=d,vv=v,A=a;
	return D+(V*V-vv*vv)*1.0/(2.0*A);
}
ll d[MAXN],v[MAXN],a[MAXN];
ll p[MAXN],l[MAXN],r[MAXN];
namespace Baoli{
	bool vis[MAXN];
	ll val[MAXN];
	pair<ll,ll>nv[MAXN];
	ll Do(){
		for(int i=1;i<=n;++i){
			nv[i]={l[i],r[i]};
		}
		sort(nv+1,nv+n+1);
		//~ cout<<endl;
		//~ for(int i=1;i<=n;++i){
			//~ cout<<nv[i].first<<" "<<nv[i].second<<endl;
		//~ }
		ll ans=0;
		ll st=1;
		while(st<=n&&nv[st].first==0){
			st++;
			continue;
		}
		ll L=nv[st].first,R=nv[st].second;
		for(int i=st+1;i<=n;++i){
			//cout<<"L"<<L<<" "<<R<<endl;
			if(R<nv[i].first){
				ans++;
				//cout<<i<<" "<<L<<" "<<R<<endl;
				L=nv[i].first,R=nv[i].second;
			}else{
				L=max(L,nv[i].first);
				R=min(R,nv[i].second);
			}
		}
		return ans+1;
	};
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;++i){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;++i){
			cin>>p[i];
		}
		ll ans1=0;
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		for(int i=1;i<=n;++i){
			if(a[i]==0){
				if(v[i]>V){
					ll id=lower_bound(p+1,p+m+1,d[i])-p;
					if(id<=m){
						l[i]=id;
						r[i]=m;
						ans1++;
					}
				}
			}else if(a[i]>0){
				ll vm=nd(d[i],v[i],a[i])+1;
				if(v[i]>V){
					vm=d[i];
				}
				ll id=lower_bound(p+1,p+m+1,vm)-p;
				if(id<=m&&p[id]>=vm){
					l[i]=id;
					r[i]=m;
					ans1++;
				}
			}else{
				if(v[i]<=V){
					continue;
				}
				ll vm=ceil(nd(d[i],v[i],a[i]))-1;
				//cout<<double(nd(d[i],v[i],a[i]))<<" "<<ceil(nd(d[i],v[i],a[i]))<<" "<<vm<<endl;
				ll id=lower_bound(p+1,p+m+1,d[i])-p;
				if(id<=m&&d[i]<=p[id]&&p[id]<=vm){
					l[i]=id;
					if(vm>=p[m]){
						r[i]=m;
					}else{
						r[i]=upper_bound(p+1,p+m+1,vm)-p-1;
					}
					//cout<<l[i]<<" "<<r[i]<<" "<<d[i]<<" "<<vm<<" "<<(p[l[i]-1]<d[i]&&p[r[i]+1]>vm)<<endl;
					ans1++;
				}
			}
		}
		cout<<ans1<<" ";
		if(ans1==0){
			cout<<m<<endl;
			continue;
		}
		ll ans2=Baoli::Do();
		cout<<m-ans2<<endl;
		//~ for(int i=1;i<=n;++i){
			//~ cout<<l[i]<<" "<<r[i]<<endl;
		//~ }
		//~ return 0;
		//~ if(T==18){
			//~ return 0;
		//~ }
	};
	return 0;
}
