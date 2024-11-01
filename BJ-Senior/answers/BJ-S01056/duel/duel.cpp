#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], cnt[maxn], rem[maxn], n, mx;
signed main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
		mx = max(mx, a[i]);
	}
	for (int p = 1; p <= mx; ++p) rem[p] = cnt[p];
	int i = 1, j = 2;
	while (i <= mx) {
		while (j <= i) ++j;
		while (cnt[i] && j <= mx) {
			if (cnt[i] >= rem[j]) {
				cnt[i] -= rem[j];
				rem[j] = 0;
				++j;
			} else {
				rem[j] -= cnt[i];
				cnt[i] = 0;
			}
		}
		++i;
	}
	int ans = 0;
	for (int p = 1; p <= mx; ++p) ans += cnt[p];
	cout << ans << endl;
	return 0;
}