#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

char g[N][N];
bool st[N][N];

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int T;
	cin >> T;
	while (T -- ) {
		memset(st, 0, sizeof st);
		int n, m, k;
		cin >> n >> m >> k;
		int x, y, d;
		cin >> x >> y >> d;
		x --, y -- ;
		for (int i = 0; i < n; i ++ ) {
			cin >> g[i];
		}
		st[x][y] = 1;
		int cnt = 1;
		while (k -- ) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				d = (d + 1) % 4;
				continue;
			}
			if (g[nx][ny] == 'x') {
				d = (d + 1) % 4;
				continue;
			}
			x = nx, y = ny;
			if (!st[x][y]) {
				cnt ++ ;
				st[x][y] = 1;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
