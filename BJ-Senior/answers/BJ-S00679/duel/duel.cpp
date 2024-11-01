#include<bits/stdc++.h>
#define ull unsigned long long
#define uint unsigned
#define ll long long
#define inf 1000000000
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define pb push_back
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define mkp make_pair
#define fi first
#define se second
#define cmh(sjy) while(sjy--)
using namespace std;
void fre(){
	freopen("duel.in","r",stdin),freopen("duel.out","w",stdout);
}
inline void chkmax(int &x,int y){ x=std::max(x,y); }
inline void chkmin(int &x,int y){ x=std::min(x,y); }
const int maxn=100005;
int n,a[maxn];
void SOlvE(){
	cin>>n;
	F(i,1,n)cin>>a[i];
	set<pii>s1,s2;
	F(i,1,n)s1.insert(mkp(a[i],i)),s2.insert(mkp(a[i],i));
	int ans=0;
	for(;;){
		if(s1.empty()||s2.empty())break;
		auto it=s1.begin(); 
		s1.erase(it);
		int x=it->fi,y=it->se;
		s2.erase(mkp(x,y));
		auto it1=s2.lower_bound(mkp(x,inf));
		if(it1==s2.end())break;
		int p=it1->second;
		++ans;
		s2.erase(it1);
	}
	cout<<(n-ans);
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	fre();
	int multi=1;
	F(_,1,multi)SOlvE();
}
// g++ duel.cpp -o a -std=c++14 -static -O2