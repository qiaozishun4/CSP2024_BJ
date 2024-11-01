#include <bits/stdc++.h>
#define mp make_pair
#define ep emplace
#define eb emplace_back
using namespace std;
using ll=long long;
using pii=array<int,2>;
using pll=array<ll,2>;

namespace Solution {
	constexpr int N=2e5+10;
	constexpr int A=1e6;
	int n,a[N];
	struct segtree {
		ll val[A<<2],lazy[A<<2];
		void init() {
			memset(val,-1,sizeof(val));
			memset(lazy,0,sizeof(lazy));
		}
		void pushup(int p) {
			val[p]=max(val[p<<1],val[p<<1|1]);
		}
		void update(int p,ll v) {
			if(val[p]==-1) return;
			val[p]+=v;
			lazy[p]+=v;
		}
		void update(int i,ll v,int p,int nl,int nr) {
			if(nl==nr) {
				val[p]=max(val[p],v);
				return;
			}
			pushdown(p);
			int mid=(nl+nr)>>1;
			if(i<=mid) update(i,v,p<<1,nl,mid);
			else update(i,v,p<<1|1,mid+1,nr);
			pushup(p);
		}
		void pushdown(int p) {
			if(!lazy[p]) return;
			update(p<<1,lazy[p]);
			update(p<<1|1,lazy[p]);
			lazy[p]=0;
		}
		void add(int l,int r,ll v,int p,int nl,int nr) {
			if(val[p]==-1) return;
			if(l<=nl&&nr<=r) {
				update(p,v);
				return;
			}
			pushdown(p);
			int mid=(nl+nr)>>1;
			if(l<=mid) add(l,r,v,p<<1,nl,mid);
			if(r>mid) add(l,r,v,p<<1|1,mid+1,nr);
			pushup(p);
		}
		ll query(int l,int r,int p,int nl,int nr) {
			if(l<=nl&&nr<=r) {
				return val[p];
			}
			pushdown(p);
			int mid=(nl+nr)>>1;
			ll res=-1;
			if(l<=mid) res=max(res,query(l,r,p<<1,nl,mid));
			if(r>mid) res=max(res,query(l,r,p<<1|1,mid+1,nr));
			return res;
		}
	} tr[2];
	void init() {
		for(int k=0;k<2;++k) tr[k].init();
	}
	void solve() {
		init();
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i];
		int m=0;
		for(int i=1;i<=n;++i) m=max(m,a[i]);
		for(int i=0;i<2;++i) tr[i].update(1,0,1,1,m);
		ll u[2];
		for(int i=1;i<=n;++i) {
			for(int k=0;k<2;++k) {
				if(a[i]==a[i-1]) tr[k].add(1,m,a[i],1,1,m);
				u[k]=tr[!k].query(1,m,1,1,m);
				ll t=tr[!k].query(a[i]+1,a[i]+1,1,1,m);
				if(t>=0) u[k]=max(u[k],t+a[i]);
			}
			for(int k=0;k<2;++k) {
				tr[k].update(a[i]+1,u[k],1,1,m);
			}
		}
		ll ans=0;
		for(int k=0;k<2;++k) ans=max(ans,tr[k].query(1,m,1,1,m));
		cout<<ans<<'\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T=1;
	cin>>T;
	while(T--) {
		Solution::solve();
	}
	return 0;
}