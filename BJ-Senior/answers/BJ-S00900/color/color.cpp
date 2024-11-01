#include <bits/stdc++.h>
using namespace std;
const int N = 17;
int T, n, a[N], c[N], ans;
void dfs(int step) {
	if (step > n) {
		int lstr = 0, lstb = 0, tot = 0;
		for (int i = 1; i <= n; i++) {
			if (c[i] == 1) tot += (a[lstr] == a[i] ? a[i] : 0), lstr = i;
			else tot += (a[lstb] == a[i] ? a[i] : 0), lstb = i;
		}
		ans = max(ans, tot); return;
	}
	c[step] = 1, dfs(step + 1);
	c[step] = 2, dfs(step + 1);
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		ans = 0, dfs(1);
		cout << ans << '\n';
	}
	return 0;
}