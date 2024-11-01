#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char mp[1005][1005];
int n, m;
bool vis[1005][1005];
const int dy[] = {1, 0, -1, 0}, dx[] = {0, 1, 0, -1};
bool chk(int x, int y) {return x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] == '.';}
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		memset(vis, 0, sizeof(vis));
		int sx, sy, dir, k;
	cin >> n >> m >> k;
	cin >> sx >> sy >> dir;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) cin >> mp[i][j];
	int x = sx, y = sy, cnt;
	vis[sx][sy] = 1;
	while(k--){
		int nx = x+dx[dir], ny = y+dy[dir];
		if(chk(nx, ny)) vis[x=nx][y=ny] = true;
		else dir = (dir+1)%4;
	}
	cnt = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(vis[i][j]) cnt++;
	cnt--;
	cout << cnt << endl;
	}
	return 0;
}
