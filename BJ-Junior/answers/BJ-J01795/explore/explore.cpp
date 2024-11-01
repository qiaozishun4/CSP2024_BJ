#include <iostream>
#include <cstdio>
using namespace std;

int t, n, m, k;
char map[1010][1010];

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		int x, y, d;
		cin >> x >> y >> d;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> map[i][j];
		if (d == 0 && map[x][y + 1] == 'x') cout << 0;
		if (d == 1 && map[x + 1][y] == 'x') cout << 0;
		if (d == 2 && map[x][y - 1] == 'x') cout << 0;
		if (d == 3 && map[x - 1][y] == 'x') cout << 0;
		cout << 1;
	}
}