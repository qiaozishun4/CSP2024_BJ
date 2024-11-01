#include<iostream>
#include<cstring>
using namespace std;
int T;
int n, m, k;
int x, y, d;
char mp[1005][1005];
bool vis[1005][1005];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while (T--) {
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				cin >> mp[i][j];
		}
		memset(vis, false, sizeof(vis));
		vis[x][y] = true;
		int ans = 1;
		for (int i = 1; i <= k; i++) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && mp[xx][yy] == '.') {
				x = xx;
				y = yy;
				if (vis[x][y] == false) {
					vis[x][y] = true;
					ans++;
				}
			} else {
				d = (d + 1) % 4;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}