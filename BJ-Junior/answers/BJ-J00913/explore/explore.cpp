#include <bits/stdc++.h>
using namespace std;
struct pos {
	char type;
	bool flag;
} a[1005][1005];
void sett () {
	for (int i = 1; i <= 1005; i++) {
		for (int j = 1; j <= 1005; j++) {
			a[i][j].flag = false;
		}
	}
}
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		sett();
		int ans = 1;
		int n, m, k;
		cin >> n >> m >> k;
		int x, y ,d;
		cin >> x >> y >> d;
		for (int j = 1; j <= n; j++) {
			for (int u = 1; u <= m; u++) {
				cin >> a[j][u].type;
			}
		}
		a[x][y].flag = true;
		for (int j = 1; j <= k; j++) {
			if (d == 0) {
				if (1 <= y + 1 && y + 1 <= m && a[x][y + 1].type == '.') {
					y += 1;
					ans++;
					if (a[x][y].flag == true) {
						ans--;
					}
					a[x][y].flag = true;
					//cout << x << " " << y << " " << ans << endl;
				} else {
					d = (d + 1) % 4;
				}
			} else if (d == 1) {
				if (1 <= x + 1 && x + 1 <= n && a[x + 1][y].type == '.') {
					x += 1;
					ans++;
					if (a[x][y].flag == true) {
						ans--;
					}
					a[x][y].flag = true;
					//cout << x << " " << y << " " << ans << endl;
				} else {
					d = (d + 1) % 4;
				}
			} else if (d == 2) {
				if (1 <= y - 1 && y - 1 <= m && a[x][y - 1].type == '.') {
					y -= 1;
					ans++;
					if (a[x][y].flag == true) {
						ans--;
					}
					a[x][y].flag = true;
					//cout << x << " " << y << " " << ans << endl;
				} else {
					d = (d + 1) % 4;
				}
			} else {
				if (1 <= x - 1 && x - 1 <= n && a[x - 1][y].type == '.') {
					x -= 1;
					ans++;
					if (a[x][y].flag == true) {
						ans--;
					}
					a[x][y].flag = true;
					//cout << x << " " << y << " " << ans << endl;
				} else {
					d = (d + 1) % 4;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
