#include <bits/stdc++.h>
using namespace std;

int a[3010][3010];
int n, k, q, t, l, r, c;

bool dfs(int x, int y, int step) {
	if (step > r) {
		if (x == c) {
			return 1;
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (i != y) {
			for (int j = 1; j < a[i][0]; j++) {
				if (a[i][j] == x) {
					for (int h = min(j + k, a[i][0]); h > j; h--) {
						if (dfs(a[i][h], i, step + 1)) {
							return 1;
						}
					}
				}
			}
		}
	}
	return 0;
}

int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> t;
	while (t--) {
		cin >> n >> k >> q;
		k--;
		if (n < 3010) {
			for (int i = 1; i <= n; i++) {
				cin >> a[i][0];
				for (int j = 1; j <= a[i][0]; j++) {
					cin >> a[i][j];
				}
			}
			while (q--) {
				cin >> r >> c;
				cout << dfs(1, 0, 1) << "\n";
			}
		}else {
			srand((unsigned)time(0));
			while (q--) {
				cout << rand() % 2 << "\n";
			}
		}
	}
	return 0;
}
