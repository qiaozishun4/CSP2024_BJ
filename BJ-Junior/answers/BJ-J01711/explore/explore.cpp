#include <bits/stdc++.h>

using namespace std;

int t;
int n, m, k, ans = 1, x, y, d;
char Map[1001][1001];

bool Is_empty() {
	if (d == 0)
		return Map[x][y + 1] == '.' && y != m;
	if (d == 1)
		return Map[x + 1][y] == '.' && x != n;
	if (d == 2)
		return Map[x][y - 1] == '.' && y != 1;
	return Map[x - 1][y] == '.' && x != 1;
}

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		ans = 1;
		scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &d);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> Map[i][j];
		for (int i = 1; i <= k; i++) {
			if (Is_empty()) {
				if (d == 0) y++;
				else if (d == 1) x++;
				else if (d == 2) y--;
				else x--;
				ans++;
			}
			else
				d = (d + 1) % 4;
		}
		printf("%d\n", ans);
	}
	return 0;
}
