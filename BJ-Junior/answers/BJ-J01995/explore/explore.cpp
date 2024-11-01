#include <bits/stdc++.h>
using namespace std;
int t, n, m, k;
int xx, yy, dd;
char c[1010][1010];
bool yes[1010][1010], vis[1010][1010];
inline bool ok(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		memset(vis, 0, sizeof(vis));
		memset(yes, 0, sizeof(yes));
		memset(c, 0, sizeof(c));
		scanf("%d%d%d%d%d%d", &n, &m, &k, &xx, &yy, &dd);
		for (int i = 1; i <= n; i++) {
			scanf("%s", c[i] + 1);
			for (int j = 1; j <= m; j++) {
				yes[i][j] = (c[i][j] == '.');
			}
		}
		vis[xx][yy] = 1;
		while (k--) {
			int dx = dir[dd][0], dy = dir[dd][1];
			if (ok(xx + dx, yy + dy) && yes[xx + dx][yy + dy]) {
				xx += dx;
				yy += dy;
				vis[xx][yy] = 1;
			} else {
				dd = (dd + 1) % 4;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				ans += vis[i][j];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}