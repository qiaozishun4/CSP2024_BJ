#include <bits/stdc++.h>
using namespace std;

int vis[1005][1005];
char c[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int k, t, x0, y0, d0, n, m;
	cin >> t;
	for (int l = 1; l <= t; l++)
	{
		cin >> n >> m >> k;
		cin >> x0 >> y0 >> d0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				vis[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> c[i][j];
			}
		}
		int cnt = 1;
		vis[x0][y0] = 1;
		for (int i = 1; i <= k; i++)
		{
			int sx = x0 + dx[d0];
			int sy = y0 + dy[d0];
			if (1 <= sx && sx <= n && 1 <= sy && sy <= m && c[sx][sy] != 'x')
			{
				x0 = sx, y0 = sy;
				if (!vis[x0][y0])
				{
					vis[x0][y0] = 1;
					cnt++;
				}
			}
			else
			{
				d0 = (d0 + 1) % 4;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

