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

int Test = 1,Case = 1;

inline string bin(int x,int len){
	if(!len)	return "";
	return bin(x>>1,len-1)+to_string(x&1);
}

constexpr int N = 2e5+5;

int a[N],n;

namespace BF{
	int check(int st){
		int lst[2] = {0,0},res = 0;
		for(int i=1;i<=n;i++){
			int c = st>>(i-1)&1;
			if(lst[c]){
				if(a[lst[c]]==a[i])	res+=a[i];
			}
			lst[c] = i;
		}
		return res;
	}
	void solve(){
		int ans = 0;
		for(int st=0;st<(1<<n);st++){
			ans = max(ans,check(st));
		}
		cout<<ans<<"\n";
	}
}

namespace Sol1{
	constexpr int _N = 505;
	ll f[_N][_N],v[N];
	inline ll w(int l,int r){
		if(l>r)	return 0;
		return v[r]-v[l-1];
	}
	void solve(){
		ll ans = 0;
		f[1][0] = 0;
		for(int i=1;i<=n;i++)	v[i] = v[i-1]+(a[i]==a[i-1]?a[i]:0);
		for(int i=2;i<=n;i++){
			f[i][0] = w(2,i);
			for(int j=1;j<i;j++){
				f[i][j] = 0;
				for(int k=0;k<=j;k++){
					f[i][j] = max(f[i][j],f[j][k]+w(j+2,i)+(a[j+1]==a[k]?a[j+1]:0));
				}
				ans = max(ans,f[i][j]);
			}
		}
		cout<<ans<<"\n";
	}
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	if(n<=15)	BF::solve();
	else    Sol1::solve();
}

int main(){
	fi("color.in"),fo("color.out");
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>Test;
	for(;Case<=Test;++Case)	solve();
	return 0;
}