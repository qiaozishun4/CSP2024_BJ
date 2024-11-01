#include<bits/stdc++.h>
using namespace std;
int n, m, k, t;
bool vis[1005][1005];
char maps[1005][1005];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, nx, ny;
void work(int x, int y, int d)
{
	for(int i = 1; i <= k; i ++)
	{
		nx = x + dx[d];
		ny = y + dy[d];
		if(nx < 1 || nx > n || ny < 1 || ny > m || maps[nx][ny] == 'x') d = (d + 1) % 4;
		else vis[nx][ny] = 1, x = nx, y = ny;
	}
	return;
}
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int x, y, d;
	cin >> t;
	while(t --)
	{
		cin >> n >> m >> k >> x >> y >> d;
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= m; j ++)
			{
				cin >> maps[i][j];
			}
		}
		memset(vis, 0, sizeof(vis));
		vis[x][y] = 1;
		work(x, y, d);
		int ans = 0;
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= m; j ++)
			{
				ans += vis[i][j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
