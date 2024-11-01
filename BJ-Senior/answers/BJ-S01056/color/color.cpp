#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2005;
int n, a[200005], clr[20], f[maxn][maxn];
signed main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T; cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		if (n <= 15) {
			int ans = 0;
			for (int i = 0; i < (1 << n); ++i) {
				int cur = 0;
				for (int j = 1; j <= n; ++j) {
					clr[j] = (i >> (j - 1)) & 1;
				}
				int lst = 0;
				for (int j = 1; j <= n; ++j) {
					if (clr[j] == 0) continue;
					cur += (a[lst] == a[j]) * a[lst];
					lst = j;
				}
				lst = 0;
				for (int j = 1; j <= n; ++j) {
					if (clr[j] == 1) continue;
					cur += (a[lst] == a[j]) * a[lst];
					lst = j;
				}
				ans = max(ans, cur);
			}
			cout << ans << endl;
			continue;
		} else if (n <= 2000) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= i; ++j) {
					f[j][i] = 0;
				}
			}
			for (int r = 1; r <= n; ++r) {
				for (int l = 1; l < r; ++l) {
					f[l][r] = max(f[l][r], f[l][r - 1] + (a[r] == a[r - 1]) * a[r]);
					f[r][r] = max(f[r][r], f[l][r - 1] + (a[r] == a[l - 1]) * a[r]);
				}
			}
			int ans = 0;
			for (int l = 1; l <= n; ++l) {
				ans = max(ans, f[l][n]);
			}
			cout << ans << endl;
			continue;
		}
	}
	return 0;
}