#include<bits/stdc++.h>
#define ull unsigned long long
#define uint unsigned
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define pb push_back
#define inf 2147483647
#define SZ(x) ((int)x.size())
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define cmh(sjy) while(sjy--)
#define lowbit(x) (x&(-x))
using namespace std;
void fre(){
	freopen("arena.in","r",stdin),freopen("arena.out","w",stdout);
}
inline void chkmax(int &x,int y){ x=std::max(x,y); }
inline void chkmin(int &x,int y){ x=std::min(x,y); }
const int maxn=300005;
int inita[maxn],c[maxn],n,zsy,multi,XXX[5],a[maxn],k,b[maxn],lst[maxn],nxt[maxn],m,qwq[maxn];
string d[19];
namespace Brute{
	vector<int>vec;
	set<int>res;
	void dfs(int u){
		if(u>(1<<m)){
			// qwq
			F(i,1,(1<<m))lst[i]=i;
			F(i,1,m){
				F(j,1,(1<<(m-i))){
					const int l=lst[(j<<1)-1],r=lst[j<<1];
					if(d[i][j]=='0')nxt[j]=(b[l]>=i)?l:r;
					else nxt[j]=(b[r]>=i)?r:l;
				}
				F(j,1,(1<<(m-i)))lst[j]=nxt[j];
			}
			res.insert(lst[1]);
			return;
		}
		F(i,0,m)b[u]=i,dfs(u+1);
	}
	ll Sol(int x){
		m=0,res.clear();
		for(;(1<<m)<x;++m);
		F(i,1,x)b[i]=a[i];
		dfs(x+1);
		ll ans=0;
		for(int i:res)ans+=i;
		return ans;
	}
	void Solve(){
		ll ans=0;
		F(i,1,zsy){
			ll val=Sol(c[i]);
			val*=i;
			ans^=val;
		}
		cout<<ans<<endl;
	}
}
namespace SubA{
	ll Sol(int m){
		F(i,1,(1<<m))b[i]=a[i],lst[i]=i;
		F(i,1,m){
			F(j,1,(1<<(m-i))){
				const int l=lst[(j<<1)-1],r=lst[j<<1];
				if(d[i][j]=='0')nxt[j]=(b[l]>=i)?l:r;
				else nxt[j]=(b[r]>=i)?r:l;
			}
			F(j,1,(1<<(m-i)))lst[j]=nxt[j];
		}
		return lst[1];
	}
	void Solve(){
		F(m,0,k)qwq[1<<m]=Sol(m);
		ll ans=0;
		F(i,1,zsy){
			ll val=qwq[c[i]];
			val*=i;
			ans^=val;
		}
		cout<<ans<<endl;
	}
}
void Realsolve(){
	if(n<=8)return Brute::Solve(),void();
	SubA::Solve();
}
void SOlvE(){
	cin>>n>>zsy,k=0;
	F(i,1,n)cin>>inita[i];
	F(i,1,zsy)cin>>c[i];
	for(;(1<<k)<n;++k);
	F(i,1,k)cin>>d[i],d[i]=' '+d[i];
	int multi; cin>>multi;
	F(_,1,multi){
		F(i,0,3)cin>>XXX[i];
		F(i,1,n)a[i]=inita[i]^XXX[i%4];
		Realsolve();
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	fre();
	int zsyqwq=1;
	F(_,1,zsyqwq)SOlvE();
}
// g++ arena.cpp -o a -std=c++14 -O2