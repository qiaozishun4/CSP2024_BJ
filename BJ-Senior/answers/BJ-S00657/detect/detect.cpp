#include <bits/stdc++.h>
#define mp make_pair
#define ep emplace
#define eb emplace_back
using namespace std;
using ll=long long;
using pii=array<int,2>;
using pll=array<ll,2>;

// csy haoshan /bx csy

namespace Solution {
	constexpr int N=1e5+10;
	constexpr int L=1e6+10;
	int n,m,l,v;
	struct Car {
		int d,v0,a;
	} car[N];
	int p[N],csy[L],cnt[L],ans1,ans2;
	void init() {
		memset(csy,0,sizeof(csy));
		memset(cnt,0,sizeof(cnt));
		ans1=ans2=0;
	}
	void seg(int a,int b) {
		cnt[a]++,cnt[b+1]--;
		ans1+=csy[b]-csy[a-1]!=0;
		cout<<a<<' '<<b<<'\n';		 
	}
	void noacc(int d,int v0) {
		if(v0>v) seg(d,l);
	}
	void posacc(int d,int v0,int a) {
		if(v0>v) {
			seg(d,l);
			return;
		}
		int k=d+(v*v-v0*v0)/(a<<1)+1;
		if(k>l) return;
		seg(k,l);
	}
	void negacc(int d,int v0,int a) {
		if(v0<=v) return;
		a=abs(a);
		int k=d+(v0*v0-v*v)/(a<<1);
		if((v0*v0-v*v)%(a<<1)) k++;
		k--;
		k=min(k,l);
		seg(d,k);
	}
	void solve() {
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;++i) {
			int d,v0,a;
			cin>>d>>v0>>a;
			car[i]={d,v0,a};
		}
		for(int i=1;i<=m;++i) {
			cin>>p[i];
			csy[p[i]]++;
		}
		for(int i=1;i<=l;++i) csy[i]+=csy[i-1];
		for(int i=1;i<=n;++i) {
			if(car[i].a==0) noacc(car[i].d,car[i].v0);
			else if(car[i].a>0) posacc(car[i].d,car[i].v0,car[i].a);
			else if(car[i].a<0) negacc(car[i].d,car[i].v0,car[i].a);
		}
		for(int i=1;i<=l;++i) cnt[i]+=cnt[i-1];
		for(int i=1;i<=m;++i) {
			if(!cnt[p[i]]) ans2++;
		}
		cout<<ans1<<' '<<ans2<<'\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T=1;
	cin>>T;
	while(T--) {
		Solution::solve();
	}
	return 0;
}