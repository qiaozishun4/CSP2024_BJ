#include <bits/stdc++.h>
using namespace std;

int n, m, k, x, y, d, ans;
char mp[1005][1005];
int vis[1005][1005];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y)
{
	if (!vis[x][y]) ans++;
	if (k == 0) return;
	vis[x][y] = 1;
	int xx = x + dx[d], yy = y + dy[d];
	if (1 > xx || xx > n || 1 > yy || yy > m || mp[xx][yy] == 'x')
	{
		d = (d + 1) % 4;
		k--;
		dfs(x, y);
	}
	else
	{
		k--;
		dfs(xx, yy);
	}
}

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d %d %d %d %d", &n, &m, &k, &x, &y, &d);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf(" %c", &mp[i][j]);
			}
		}
		ans = 0;
		dfs(x, y);
		printf("%d\n", ans);
		memset(vis, 0, sizeof(vis));
	}
	return 0;
}