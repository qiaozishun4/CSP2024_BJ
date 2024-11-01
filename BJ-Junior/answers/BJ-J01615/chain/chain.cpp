#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

// Only Test Case #1 !!!
// AKCSP(?)

const int N = 1e5 + 10;

vector<int> S[N];

int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int T;
	cin >> T;
	while (T -- ) {
		int n, k, q;
		cin >> n >> k >> q;
		for (int i = 0; i < n; i ++ ) {
			int x;
			cin >> x;
			for (int j = 0; j < x; j ++ ) {
				int y;
				cin >> y;
				S[i].push_back(y);
			}
		}
		while (q -- ) {
			int r, c;
			cin >> r >> c;
			int ans = 0;
			for (int i = 0; i < n; i ++ ) {
				int flag = 0;
				for (int j = 0; j < (int)S[i].size(); j ++ ) {
					if (S[i][j] == 1) flag = k - 1;
					if (flag && S[i][j] == c) ans = 1;
					flag -- ;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
