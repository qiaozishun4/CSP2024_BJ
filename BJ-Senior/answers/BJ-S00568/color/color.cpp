#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5, M = 1e6 + 5;
int T;
int n;
int a[N];
int col[N];

signed main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}

		int ans = 0;

		for (int i = 0; i < (1 << n); i++) {
			for (int j = 1; j <= n; j++) {
				int bit = ((i >> (j - 1)) & 1);
				col[j] = bit;
			}
			int sum = 0;
			for (int k = 1; k <= n; k++) {
				for (int l = k - 1; l >= 1; l--) {
					if (col[k] == col[l]) {
						if (a[l] == a[k]) sum += a[k];
						break;
					}
				}
			}
			ans = max(ans, sum);
		}

		printf("%lld\n", ans);

	}
	return 0;
}