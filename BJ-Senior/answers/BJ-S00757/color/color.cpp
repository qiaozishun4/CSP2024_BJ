#include <iostream>
#include <cstdlib>
using namespace std;
int T, n, a[200005];
long long ans = 0;
void dfs(int x, int r, int b, long long cnt) {
	if (x == n + 1) {
		ans = max(ans, cnt);
		return;
	}
	long long addr = 0, addb = 0;
	if (r && a[r] == a[x]) addr = a[x];
	if (b && a[b] == a[x]) addb = a[x];
	dfs(x + 1, x, b, cnt + addr);
	dfs(x + 1, r, x, cnt + addb);
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		ans = 0;
		dfs(1, 0, 0, 0);
		cout << ans << '\n';
	}
	return 0;
}
