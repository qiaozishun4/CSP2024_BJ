#include <iostream>
#include <cstring>
using namespace std;

int n, m, k;
int ans = 1;
char a[1005][1005];
bool vis[1005][1005];

void dfs(int x, int y, int d, int ct)
{
	if (ct == k + 1)
	{
		return;
	}
	int nx, ny;
	if (d == 0)
	{
		nx = x;
		ny = y + 1;
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m &&a[nx][ny] == '.')
		{
			ans++;
			if (vis[nx][ny]) ans--;
			vis[nx][ny] = 1;
			dfs(nx, ny, d, ct + 1);
		}
		else
		{
			dfs(x, y, (d + 1) % 4, ct + 1);
		}
	}
	else if (d == 1)
	{
		nx = x + 1;
		ny = y;
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.')
		{
			ans++;
			if (vis[nx][ny]) ans--;
			vis[nx][ny] = 1;
			dfs(nx, ny, d, ct + 1);
		}
		else
		{
			dfs(x, y, (d + 1) % 4, ct + 1);
		}
	}
	else if (d == 2)
	{
		nx = x;
		ny = y - 1;
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.')
		{
			ans++;
			if (vis[nx][ny]) ans--;
			vis[nx][ny] = 1;
			dfs(nx, ny, d, ct + 1);
		}
		else
		{
			dfs(x, y, (d + 1) % 4, ct + 1);
		}
	}
	else if (d == 3)
	{
		nx = x - 1;
		ny = y;
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.')
		{
			ans++;
			if (vis[nx][ny]) ans--;
			vis[nx][ny] = 1;
			dfs(nx, ny, d, ct + 1);
		}
		else
		{
			dfs(x, y, (d + 1) % 4, ct + 1);
		}
	}
	return;
}

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int T;
	cin >> T;
	int x0, y0, d0;
	for (int i = 1; i <= T; i++)
	{
		cin >> n >> m >> k;
		cin >> x0 >> y0 >> d0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> a[i][j];
			}
		}
		vis[x0][y0] = 1;
		dfs(x0, y0, d0, 1);
		cout << ans << endl;
		ans = 1;
		memset(vis, 0, sizeof(vis));
	}
	return 0;
}