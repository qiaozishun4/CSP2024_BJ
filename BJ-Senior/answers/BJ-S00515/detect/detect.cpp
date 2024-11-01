#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,l,V,d[100005],v[100005],a[100005],p[100005];
bool f[100005],h[100005];
vector<ll> g[100005];
long double calc(ll v,ll a,ll s){
	return sqrt(1.0*v*v+2.0*a*s);
}
bool chk(){
	for(ll i=1;i<=n;i++){
		if(h[i]&&!f[i]) return 0;
	}return 1;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(),cout.tie();
	cin>>t;
	while(t--){
		ll ans=0,cnt=1e18;
		cin>>n>>m>>l>>V;
		for(ll i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(ll i=1;i<=m;i++){
			cin>>p[i];g[i].clear();h[i]=0;f[i]=0;
		}
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				if(p[j]<d[i]) continue;
				ll s=p[j]-d[i];
				if(calc(v[i],a[i],s)<=0) break;
				if((a[i]!=0&&calc(v[i],a[i],s)>V)||(a[i]==0&&v[i]>V)){
					g[j].push_back(i);h[i]=1;
				}
			}
		}
		for(ll i=1;i<=n;i++) ans+=h[i];
		for(ll i=1;i<(1<<m);i++){
			ll p=0;
			for(ll j=1;j<=n;j++) f[j]=0;
			for(ll j=0;j<m;j++){
				if((i>>j)&1){
					for(auto k:g[j+1]) f[k]=1;
					p++;
				}
			}
			if(chk()){
				cnt=min(cnt,p);
			}
		}
		cout<<ans<<" "<<m-cnt<<"\n";
	}
	return 0;
}
