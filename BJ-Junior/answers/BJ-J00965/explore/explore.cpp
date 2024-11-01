#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;
int n, m, k, ans;
char c[N][N];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool vis[N][N];

int main(){
	ios::sync_with_stdio(false);
	freopen("explore.in", "r", stdin); freopen("explore.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		int x, y, d, cnt = 0;
		cin >> n >> m >> k >> x >> y >> d;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j) cin >> c[i][j];
		}
		memset(vis, 0, sizeof(vis));
		while(cnt <= k){
			vis[x][y] = 1;
			if(cnt == k) break;
			int xx = x + dx[d], yy = y + dy[d];
			if(xx < 1 || xx > n || yy < 1 || yy > m || c[xx][yy] == 'x'){
				d = (d + 1) % 4;
			}else x = xx, y = yy;
			cnt++;
		}
		ans = 0;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				if(vis[i][j]) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}