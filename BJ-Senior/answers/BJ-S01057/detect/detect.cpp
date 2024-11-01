#include <bits/stdc++.h>

#define fi(x) freopen(x,"r",stdin)
#define fo(x) freopen(x,"w",stdout)
#define pb_ push_back
#define mset(x,y) memset(x,y,sizeof(x))
#define Misaka16172 sb

using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using db = double;

inline string bin(int x,int len){
	if(!len)	return "";
	return bin(x>>1,len-1)+to_string(x&1);
}

int Test = 1,Case = 1;

constexpr int N = 1e5+5,M = 1e5+5,inf = 0x3f3f3f3f;
constexpr ld eps = 1e-8;

int n,m,L,V;
int d[N],v[N],a[N],p[M];

namespace BF{
	inline bool check(int i,int j){
		if(p[i]<d[j])	return 0;
		int x = p[i]-d[j];
		ld nowv = (ld)v[j]*v[j]+(ld)2*a[j]*x;
		if(nowv-eps>(ld)V*V)	return 1;
		return 0;
	}
	int res[N];
	void init(){
		fill(res+1,res+1+n,0);
	}
	void solve(){
		init();
		int ans1 = 0;
		for(int j=1;j<=n;j++){
			for(int i=1;i<=m;i++){
				if(check(i,j))	res[j]|=(1<<(i-1));
			}
			ans1+=(bool)res[j];
			// if(res[j])	cout<<j<<"\n";
		}
		cout<<ans1<<" ";
		int ans2 = 0;
		for(int st=0;st<(1<<m);st++){
			bool f = 1;
			for(int j=1;j<=n;j++){
				if(!res[j])	continue;
				if(!(res[j]&st)){f = 0;break;}
			}
			if(f)	ans2 = max(ans2,m-__builtin_popcount(st));
		}
		cout<<ans2<<"\n";
	}
}

namespace taskAB{
	void solve(){
		int ans1 = 0;
		for(int i=1;i<=n;i++){
			if(p[m]<d[i])	continue;
			int x = p[m]-d[i];
			ld nowv = (ld)v[i]*v[i]+(ld)2*a[i]*x;
			if(nowv-eps>(ld)V*V)	ans1++;
		}
		cout<<ans1<<" "<<(ans1?m-1:m)<<"\n";
	}
}

namespace Sol{
	#define fst first
	#define snd second
	
	using P = pair<ld,ld>;
	using pii = pair<int,int>;

	vector<pii> seg;
	vector<vector<pii>> G;
	ld mx[N];
	int dis[M];
	bool vis[M];
	
	inline void init(){
		seg = vector<pii>();
	}
	inline void dij_init(){
		fill(vis,vis+1+m,0);
		fill(dis,dis+1+m,inf);
		dis[0] = 0;
	}
	inline ld getv(int id,ld pos){
		if(a[id]<0 && pos>mx[id])	return 0;
		ld x = pos-d[id];
		return sqrtl((ld)v[id]*v[id]+(ld)2*a[id]*x);
	}
	inline int nxtp(int id){
		return lower_bound(p+1,p+1+m,d[id])-p;
	}

	void dij(){
		dij_init();
		priority_queue<pii> pq;
		pq.push({0,0});
		while(!pq.empty()){
			int u = pq.top().snd;pq.pop();
			if(vis[u])	continue;
			vis[u] = 1;
			for(auto e:G[u]){
				if(dis[u]+e.snd<dis[e.fst]){
					dis[e.fst] = dis[u]+e.snd;
					pq.push({-dis[e.fst],e.fst});
				}
			}
		}
	}

	void addedge(){
		for(auto i:seg){
			int l = i.fst,r = i.snd;
			G[l-1].pb_({r,r-l});
		}
		for(int i=1;i<=m;i++)	G[0].pb_({i,m}),G[i].pb_({0,0});
		for(int i=1;i<=m;i++){
			G[i].pb_({i-1,0});
			G[i-1].pb_({i,1});
		}
	}

	void solve(){
		init();
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]<=V || d[i]>p[m])	continue;
				seg.pb_({nxtp(i),m});
			}
			else if(a[i]>0){
				if(getv(i,p[m])<=V || d[i]>p[m])	continue;
				int l = nxtp(i),r = m;
				while(l<r){
					int mid = (l+r)>>1;
					if(getv(i,p[mid])>V)	r = mid;
					else	l = mid+1;
				}
				seg.pb_({r,m});
			}
			else{
				mx[i] = min((ld)L,(-(ld)v[i]*v[i])/((ld)a[i]*2)+d[i]);
				int nxt = nxtp(i);
				if(nxt>m || getv(i,p[nxt])<=V)	continue;
				int l = nxt,r = m;
				while(l<r){
					int mid = (l+r+1)>>1;
					if(getv(i,p[mid])>V)	l = mid;
					else	r = mid-1;
				}
				seg.pb_({nxt,l});
			}
		}
		cout<<seg.size()<<" ";
		G = vector<vector<pii>>(m+5);
		addedge(),dij();
		cout<<dis[m]<<"\n";
	}
}

void solve(){
	cin>>n>>m>>L>>V;
	int mina = inf;
	for(int i=1;i<=n;i++)	cin>>d[i]>>v[i]>>a[i],mina = min(mina,a[i]);
	for(int i=1;i<=m;i++)	cin>>p[i];
	Sol::solve();
}

int main(){
	fi("detect.in"),fo("detect.out");
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>Test;
	for(;Case<=Test;++Case)	solve();
	return 0;
}

// Maybe I'll win this time.
// Hope I'm not going to become a joker.