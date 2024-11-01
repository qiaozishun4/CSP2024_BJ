#include<bits/stdc++.h>

using namespace std;

const int N = 1010;

int t;
int n, m, k;
int x, y, d;
char s[N][N];
bool vis[N][N][4];

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &d);
		memset(s, 0, sizeof s);
		memset(vis, false, sizeof vis);
		for (int i = 1; i <= n; i++)
			scanf("%s", s[i] + 1);
		while (k--)
		{
			vis[x][y][d] = true;
			int x_nxt = x, y_nxt = y;
			if (d == 0)
				y_nxt++;
			if (d == 1)
				x_nxt++;
			if (d == 2)
				y_nxt--;
			if (d == 3)
				x_nxt--;
			if (x_nxt <= 0 || x_nxt > n || y_nxt <= 0 || y_nxt > m || s[x_nxt][y_nxt] == 'x')
				d = (d + 1) % 4/*, printf("right turn, pos = %d\n", d)*/;
			else
				x = x_nxt, y = y_nxt/*, printf("go to (%d, %d)\n", x, y)*/;
			if (vis[x][y][d])
				break;
		}
		vis[x][y][d] = true;
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (vis[i][j][0] || vis[i][j][1] || vis[i][j][2] || vis[i][j][3])
					ans++;
		printf("%d\n", ans);
	}

	return 0;
}