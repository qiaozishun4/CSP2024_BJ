#include<bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
const int N = 1e3 + 5;
char c[N][N];
bool vis[N][N];
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		memset(vis, 0, sizeof(vis));
		int n, m, k;
		cin >> n >> m >> k;
		int x, y, d;
		cin >> x >> y >> d;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> c[i][j];
			}
		}
		int cnt = 1;
		while (k--) {
			vis[x][y] = 1;
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx > n || nx < 1 || ny > m || ny < 1 || c[nx][ny] == 'x') {
				d = (d + 1) % 4;
			} else {
				if (!vis[nx][ny]) {
					cnt++;
				}
				x = nx;
				y = ny;
			}
		}
		cout << cnt<< endl;
	}
	return 0;
}
