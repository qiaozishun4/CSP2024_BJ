#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int t, n, m, k, stx, sty, d, ans = 0;
char maps[maxn][maxn];
bool inbound (int x, int y) {
	return (x >= 1 && x <= n && y >= 1 && y <= m && maps[x][y]!='x');
}
int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n >> m >> k >> stx >> sty >> d;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) cin >> maps[i][j];
		int x = stx, y = sty;
		maps[x][y] = 't';
		for (int i = 0; i < k; i++) {
			int nx = x+dx[d], ny = y + dy[d];
			if (inbound(nx, ny)) {
				x = nx, y = ny;
				maps[x][y] = 't';
			}
			else d = (d+1) % 4;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (maps[i][j] == 't') ans++;
		cout << ans << '\n';
	}
	return 0;
}
