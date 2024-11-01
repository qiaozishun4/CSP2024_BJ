#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1010;
bool maze[N][N], vis[N][N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t, n, m, x, y, k, w, ans;
	cin >> t;
	char c;
	for (int i = 1; i <= t; i++)
	{
		cin >> n >> m >> k;
		cin >> x >> y >> w;
		ans = 1;
		for (int j = 1; j <= n; j++)
		{
			for (int l = 1; l <= m; l++)
			{
				cin >> c;
				maze[j][l] = (c == '.');
				vis[j][l] = false;
			}
		}
		vis[x][y] = true;
		for (int j = 1; j <= k; j++)
		{
			if (maze[x + dx[w]][y + dy[w]] == false)
			{
				w += 1;
				w %= 4;
				continue;
			}
			x += dx[w];
			y += dy[w];
			if (!vis[x][y])
			{
				vis[x][y] = true;
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}