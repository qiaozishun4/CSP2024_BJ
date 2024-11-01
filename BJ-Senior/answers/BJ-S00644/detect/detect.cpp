#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
ll t,n,m,d[100005],v[100005],ans,in[100005],f[100005],L,V,l[100005],r[100005],a[100005],p[100005];
vector<pair<ll,ll> > G[100005];
queue<ll> q; 
ll getxx(ll x){
	ll cur=lower_bound(p+1,p+m+1,x)-p;
	return cur;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>L>>V;
		for(ll i=0;i<=max(n,m);i++){
			G[i].clear();
			l[i]=r[i]=-1;
			in[i]=0;
			f[i]=-1e9;
		}
		for(ll i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(ll i=1;i<=m;i++){
			cin>>p[i];
			G[i-1].push_back({i,0ll});
			in[i]++;
		}
		for(ll i=1;i<=n;i++){
			if(!a[i]){
				if(v[i]>V&&getxx(d[i])!=m+1){
					G[getxx(d[i])-1].push_back({m,1ll});
					in[m]++;
			//		cout<<i<<" Ranged at:["<<getxx(d[i])<<","<<m<<"]\n";
				}
			}
			else if(a[i]>0&&getxx(d[i])!=m+1){
				ll l,r,mid;
				l=getxx(d[i]),r=m;
				while(l<r){
					mid=(l+r)>>1;
					if(v[i]*v[i]+2*a[i]*(p[mid]-d[i])>V*V){
						r=mid;
					}
					else{
						l=mid+1;
					}
				}
				if(l>=getxx(d[i])&&l<=m&&v[i]*v[i]+2*a[i]*(p[l]-d[i])>V*V){
					G[l-1].push_back({m,1ll});
					in[m]++;
			//		cout<<i<<" Ranged at:["<<l<<","<<m<<"]\n";
				}
			}
			else if(a[i]<0&&getxx(d[i])!=m+1){
				ll l,r,mid;
				l=getxx(d[i]),r=m;
				while(l<r){
					mid=(l+r+1)>>1;
					if(v[i]*v[i]+2*a[i]*(p[mid]-d[i])>V*V){
						l=mid;
					}
					else{
						r=mid-1;
					}
				}
				ll t=getxx(d[i]);
				if(l>=t&&l<=m&&v[i]*v[i]+2*a[i]*(p[l]-d[i])>V*V){
					G[t-1].push_back({l,1ll});
					in[l]++;
			//		cout<<i<<" Ranged at:["<<t<<","<<l<<"]\n";
				}
			}
		}
		ans=0;
		for(ll i=1;i<=n;i++){
			ll t=getxx(d[i]);
			if(t==m+1){
				continue;
			}
			if(v[i]*v[i]+2*a[i]*(p[t]-d[i])>V*V||v[i]*v[i]+2*a[i]*(p[m]-d[i])>V*V){
				ans++;
			}
		}
		cout<<ans<<" ";
		while(!q.empty()){
			q.pop();
		}
		f[0]=0;
		q.push(0);
		while(!q.empty()){
			ll cur=q.front();
			q.pop();
			for(ll i=0;i<G[cur].size();i++){
				ll to,w;
				to=G[cur][i].first;
				w=G[cur][i].second;
				in[to]--;
				f[to]=max(f[to],f[cur]+w);
				if(!in[to]){
					q.push(to);
				}
			}
		}
		cout<<m-f[m]<<endl;
	}
	return 0;
}
