#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1050;
int n, m, k, t;
int x, y, d;
char s[N][N];
bool f[N][N];

int main () {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d%d", &n, &m, &k);
		scanf("%d%d%d", &x, &y, &d);
		for (int i = 1; i <= n; i ++) {
			scanf("%s", s[i] + 1);
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				f[i][j] = false;
			}
		}
		int ans = 1;
		f[x][y] = true;
		while (k --) {
			int nx, ny, nd;
			if (d == 0) {
				nx = x, ny = y + 1;
			} else if (d == 1) {
				nx = x + 1, ny = y;
			} else if (d == 2) {
				nx = x, ny = y - 1;
			} else {
				nx = x - 1, ny = y;
			}
			if (s[nx][ny] == 'x' || (nx < 1 || nx > n) || (ny < 1 || ny > m)) {
				d = (d + 1) % 4;
			} else {
				x = nx, y = ny;
				if (! f[x][y]) {
					f[x][y] = true;
					ans ++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}