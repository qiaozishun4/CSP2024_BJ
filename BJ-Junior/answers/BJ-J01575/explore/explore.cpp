#include <iostream>
#include <cstring>
using namespace std;

int t, n, m, k, x, y, d, cnt;
char mp[1005][1005];
bool vis[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> k >> x >> y >> d;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> mp[i][j];
		memset(vis, false, sizeof vis);
		cnt = 1, vis[x][y] = true;
		for(int i = 1; i <= k; i++)
		{
			int x_new = x + dx[d], y_new = y + dy[d];
			bool flag = false;
			if(x_new < 1 || x_new > n || y_new < 1 || y_new > m) flag = true;
			if(mp[x_new][y_new] == 'x') flag = true;
			if(flag) d = (d + 1) % 4;
			else
			{
				x = x_new, y = y_new;
				if(!vis[x][y]) cnt++;
				vis[x][y] = true;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}