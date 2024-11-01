#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i--)
#define int long long
#define ull unsigned long long 
#define pii pair<int,int>
#define pk pop_back
#define pb push_back
#define fi first
#define se second
#define ll long long
#define WA cerr<<"meowww~\n";
#define WR(x) cerr<<x<<"\n";
#define C continue
#define pii pair<int,int>
#define INF
#define db double
#define eps 1e-6
#define MAXN 110001
//const int MOD=
void Umn(int &x,int y) { if(x>y)x=y;return ; }
void Umx(int &x,int y) { if(x<y)x=y;return ; }
//void MD(int &x) { if(x<0)x+=MOD;if(x>MOD)x-=MOD;return ; }
//CLEAR THE DATA!!!
//MAKE SOME CONNER
int n,m,L,V; int d[MAXN],v0[MAXN],a[MAXN]; int p[MAXN];
namespace bit
{
	int sz;
	#define lowbit(x) x&(-x)
	int tr[MAXN];
	void clear() { For(i,0,sz)tr[i]=0; }
	void add(int x,int vl) { for(x;x<=sz;x+=lowbit(x))tr[x]+=vl;return ; }
	int Q_(int x) { int rt=0; for(x;x;x-=lowbit(x))rt+=tr[x]; return rt;}
	int Q(int l,int r) { return Q_(r)-Q_(l-1); } 
}
int cnt=0;
struct meow{int l,r;};
vector<meow> q;
void init() { q.clear();bit::clear(); return ; }
db ck(int s,int p) { db sp=sqrt(v0[p]*v0[p]+2.0*a[p]*s); db qwq=(V+0.00); if(sp>qwq)return 1;else return 0; }
int clac(int p) { if(a[p]>0&&v0[p]>V) { return d[p]; }
	db nt=(V-v0[p])/(a[p]+0.0); if(nt<0.0)return -1; db s=(v0[p]*nt)+(0.50*a[p]*nt*nt); int ns;
	if(a[p]>0) { ns=ceil(s); if(!ck(ns,p)) { ns++; } }
	else { ns=s; if(!ck(ns,p)) { ns--; } }
	return ns+d[p];
}
bool cmp(meow x,meow y) { return (x.r==y.r)?(x.l<y.l):(x.r<y.r); } 
void add(int l,int r) { 
	//cerr<<"DP="<<l<<" "<<r<<"\n";
	int fr=lower_bound(p+1,p+1+m,l)-p;
	int ed=upper_bound(p+1,p+1+m,r)-p-1; 
	//cerr<<fr<<" "<<ed<<"\n";
	if(fr>ed) return ;
	//cerr<<"SP="<<l<<" "<<r<<"\n";
	q.pb({fr,ed});
	return ;
}
 main()
{
	//freopen("in2.in","r",stdin);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int _; cin>>_; For(__,1,_)
	{
		init(); cin>>n>>m>>L>>V; 
		For(i,1,n) { cin>>d[i]>>v0[i]>>a[i]; } bit::sz=m;
		For(i,1,m) cin>>p[i];
		For(i,1,n) { 
			if(a[i]==0) { if(v0[i]>V) { add(d[i],L); } C; } 
			int fs=clac(i); if(fs==-1) C; //WR(i);
			if(a[i]<0) { add(d[i],min(fs,L)); } else if(a[i]>0&&fs<=L) { add(fs,L); }
		}
		int k=q.size(); 
		sort(q.begin(),q.end(),cmp); int ans=0; 
		//for(auto i:q)cerr<<i.l<<" "<<i.r<<"\n";
		for(auto i:q) { 
			if(bit::Q(i.l,i.r)<1) { ans++; bit::add(i.r,1); }
		 }
		 cout<<k<<" "<<m-ans<<"\n";
	}
	return 0;
}