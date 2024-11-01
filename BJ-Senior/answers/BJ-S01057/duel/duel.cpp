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

constexpr int N = 1e5+5,V = 1e5+5;

int a[N],cnt[V],n;

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i],cnt[a[i]]++;
	sort(a+1,a+1+n);
	int c = unique(a+1,a+1+n)-a-1;
	int now = cnt[a[1]],ans = 0;
	for(int i=2;i<=c;i++){
		if(cnt[a[i]]>=now)	ans+=now,now = 0;
		else	ans+=cnt[a[i]],now-=cnt[a[i]];
		now+=cnt[a[i]];
	}
	cout<<n-ans;
}

int main(){
	fi("duel.in"),fo("duel.out");
	ios::sync_with_stdio(0),cin.tie(0);
	for(;Case<=Test;++Case)	solve();
	return 0;
}