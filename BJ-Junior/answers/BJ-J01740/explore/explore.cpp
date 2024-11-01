#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int t, n, m, x, y, d, k, cnt;
char a[1010][1010];
bool vis[1010][1010];

int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	while (t--) {
		cin >> n >> m >> k >> x >> y >> d;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				vis[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		cnt = 1;
		vis[x][y] = 1;
		while (k--) {
			if (d == 0) {
				if (y < m && a[x][1 + y] == '.') {
					if (!vis[x][++y]) {
						cnt++;
						vis[x][y] = 1;
					}
				}else {
					d = (d + 1) % 4;
				}
			}else if (d == 1) {
				if (x < n && a[x + 1][y] == '.') {
					if (!vis[++x][y]) {
						cnt++;
						vis[x][y] = 1;
					}
				}else {
					d = (d + 1) % 4;
				}
			}else if (d == 2) {
				if (y > 1 && a[x][y - 1] == '.') {
					if (!vis[x][--y]) {
						cnt++;
						vis[x][y] = 1;
					}
				}else {
					d = (d + 1) % 4;
				}
			}else {
				if (x > 1 && a[x - 1][y] == '.') {
					if (!vis[--x][y]) {
						cnt++;
						vis[x][y] = 1;
					}
				}else {
					d = (d + 1) % 4;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
