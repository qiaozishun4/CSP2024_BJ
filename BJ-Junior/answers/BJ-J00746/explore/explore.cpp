#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int T, n, m, k;
int x, y, d;
char a[N][N];
bool vis[N][N];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
bool is_valid(int nx, int ny) {
	if(1 <= nx && nx <= n && 1 <= ny && ny <= m && a[nx][ny] == '.') return true;
	else return false;

}
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	while(T--) {
		memset(vis, 0, sizeof(vis));
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		long long cnt = 1;
		vis[x][y] = true;
		for(int i = 1; i <= k; i++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if(is_valid(nx, ny)) {
				if(!vis[nx][ny]) cnt++;
				vis[nx][ny] = true;
				x = nx;
				y = ny;
				//cout << "x:" << x << " y:" << y << endl;
			} else {
				if(d == 3) d = 0;
				else d++;
			}
		}
		/*/cout << "vis:" << endl;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cout << vis[i][j] << " ";
			}
			cout << endl;
		}/*/
		cout << cnt << endl;
	}
	return 0;
}