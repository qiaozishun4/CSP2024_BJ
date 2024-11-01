#include<bits/stdc++.h>
using namespace std;
const int NR = 2e5 + 5;
int t;
int n, a[NR];
int ans;
void dfs(int x, int lstr, int lstb, int res) {
	if(x > n) {
		ans = max(ans, res);
		return;
	}
	if(a[lstr] == a[x]) dfs(x + 1, x, lstb, res + a[x]);
	else dfs(x + 1, x, lstb, res);
	if(a[lstb] == a[x]) dfs(x + 1, lstr, x, res + a[x]);
	else dfs(x + 1, lstr, x, res);
}
void solve() {
	ans = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	dfs(1, 0, 0, 0);
	cout << ans << endl;
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	while(t--) solve();
	return 0;
}