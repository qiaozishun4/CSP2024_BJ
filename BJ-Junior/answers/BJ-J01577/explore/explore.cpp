#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T;
int n, m, k;
int sx, sy, d;
char a[1010][1010];
bool vis[1010][1010];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int solve() {
	int x = sx, y = sy, ans = 1;
	vis[x][y] = true;
	//  the start is also an answer, so ans = 1 at begining 
	for (int i = 1; i <= k; i++) {
		int nx = x + dx[d], ny = y + dy[d];
		if (nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == 'x') {
			d = (d + 1) % 4;
		} else {
			x = nx, y = ny;
			if (!vis[x][y]) {
				ans++;
				vis[x][y] = true;
			}
		}
	}
	return ans;
}

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n >> m >> k;
		cin >> sx >> sy >> d;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		cout << solve() << endl;
		memset(vis, false, sizeof vis);
	}
	return 0;
}

/*
  	 --------
	/--------\
   /  ~   ~   \
  /	  - | -    \
--      |       --   
| ;    ? ?     ; |
--     ```      --
  \   ------   /
   \          /
    ----------
	|         |
	/         \
----           -----



*/