#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e3 + 2;
int n, m, k, x, y, d;
const int mv[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool can[N][N];
bool vis[N][N];
int ans;
void mian(){
	memset(vis, 0, sizeof(vis));
	cin >> n >> m >> k;
	cin >> x >> y >> d;
	vis[x][y] = true;
	ans = 1; 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			char c;
			cin >> c;
			can[i][j] = (c == 'x');
		}
	}
	for(int i = 1; i <= k; i++){
		int nx = x + mv[d][0], ny = y + mv[d][1];
		if(nx < 1 || ny < 1 || nx > n || ny > m || can[nx][ny]){
			d = (d + 1) % 4;
			continue;
		}
		x = nx;
		y = ny;
		if(!vis[x][y]){
			vis[x][y] = true;
			ans++;
		}
	}
	cout << ans << endl;
}
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		mian();
	}
}