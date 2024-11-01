#include <bits/stdc++.h>
#define mp make_pair
#define ep emplace
#define eb emplace_back
using namespace std;
using ll=long long;
using pii=array<int,2>;
using pll=array<ll,2>;
namespace Solution {
	constexpr int N=1e5+10;
	int n,r[N];
	void solve() {
		cin>>n;
		for(int i=1;i<=n;++i) cin>>r[i];
		sort(r+1,r+n+1);
		multiset<int> m;
		int ans=n;
		for(int i=1;i<=n;m.ep(r[i++])) {
			if(m.empty()) continue;
			auto it=m.lower_bound(r[i]);
			if(it==m.begin()) continue;
			it--;
			m.erase(it);
			ans--;
		}
		cout<<ans<<'\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int T=1;
	// cin>>T;
	while(T--) {
		Solution::solve();
	}
	return 0;
}