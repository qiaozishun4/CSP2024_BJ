#include <bits/stdc++.h>
using namespace std;
int T, n, k, q, l, x;
const int N = 1e5 + 2;
map <int, bool> mp;
int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> T;
	cin >> n >> k >> q;
	for(int i = 1; i <= n; i++) {
		cin >> l;
		for(int j = 0; j <= l - 1; j++) {
			cin >> x;
			mp[x] = true;
		}
	}
	int r, c;
	while(q--) {
		cin >> r >> c;
		if(mp.count(c) == 0 || r * k < c) cout << 0 << endl;
		else cout << 1 << endl;
	}
	return 0;
}