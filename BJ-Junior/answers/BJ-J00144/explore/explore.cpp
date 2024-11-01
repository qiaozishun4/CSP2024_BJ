#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int T, n, m, k, x, y, z, ans;
string mapp[N];
bool vis[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool Check (int x, int y)
{
	if (x >= 1 && x <= n && y >= 1 && y <= m && mapp[x][y] == '.')
		return 1;
	return 0;
}
int main ()
{
	freopen ("explore.in", "r", stdin);
	freopen ("explore.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				vis[i][j] = 0;
		cin >> x >> y >> z;
		for (int i = 1; i <= n; i++)
			cin >> mapp[i];
		for (int i = 1; i <= n; i++)
			for (int j = m; j >= 1; j--)
				mapp[i][j] = mapp[i][j - 1];
		ans = 1, vis[x][y] = 1;
		while (k--)
		{
			int nx = x + dx[z], ny = y + dy[z];
			if (Check (nx, ny))
				x = nx, y = ny;
			else 
				z = (z + 1) % 4;
			if (!vis[x][y])
			{
				//cout << "x: " << x << "	y: " << y << endl;
				ans++;vis[x][y] = 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}