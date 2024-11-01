#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define uint unsigned
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define pb push_back
#define SZ(x) ((int)x.size())
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define cmh(sjy) while(sjy--)
#define lowbit(x) (x&(-x))
using namespace std;
void fre(){
	freopen("color.in","r",stdin),freopen("color.out","w",stdout);
}
inline void chkmax(ll &x,ll y){ x=std::max(x,y); }
inline void chkmin(ll &x,ll y){ x=std::min(x,y); }
const int maxn=200005;
int a[maxn],n,lst[1000005];
ll f[maxn];
namespace seg{
	#define ls (o<<1)
	#define rs (o<<1|1)
	ll t[maxn<<2],tag[maxn<<2];
	void clear(){ memset(t,0,sizeof t),memset(tag,0,sizeof tag); }
	inline void maketag(int o,ll val){ tag[o]+=val,t[o]+=val; }
	inline void pushdown(int o){ if(tag[o])maketag(ls,tag[o]),maketag(rs,tag[o]),tag[o]=0; }
	void update(int o,int l,int r,int ql,int qr,ll val){
		if(ql<=l&&qr>=r)return maketag(o,val),void();
		int mid=(l+r)>>1; pushdown(o);
		if(ql<=mid)update(ls,l,mid,ql,qr,val);
		if(qr>mid)update(rs,mid+1,r,ql,qr,val);
		t[o]=max(t[ls],t[rs]);
	}
	ll query(int o,int l,int r,int pos){
		if(l==r)return t[o];
		int mid=(l+r)>>1; pushdown(o);
		return (pos<=mid)?query(ls,l,mid,pos):query(rs,mid+1,r,pos);
	}
}
void SOlvE(){
	cin>>n;
	F(i,1,n)cin>>a[i],lst[a[i]]=0;
	seg::clear();
	F(i,1,n){
		ll mx=seg::t[1];
		ll val=mx;
		if(lst[a[i]])chkmax(val,seg::query(1,0,n,lst[a[i]])+a[i]);
		seg::update(1,0,n,i-1,i-1,val);
		lst[a[i]]=i;
		if(i>1&&a[i]==a[i-1])seg::update(1,0,n,0,i-2,a[i]);
	}
	cout<<(seg::t[1])<<endl;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	fre();
	int multi=1; cin>>multi;
	F(_,1,multi)SOlvE();
}
// g++ color.cpp -o a -std=c++14 -O2