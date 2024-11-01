#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 1e3+5;
bool vis[maxn][maxn];
char a[maxn][maxn];

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		int n, m, k;
		cin >> n >> m >> k;
		int x, y, d;
		cin >> x >> y >> d;
		for(int j = 1; j <= n; j++)
			for(int kk = 1; kk <= m; kk++)
			{
				cin >> a[j][kk];
				vis[j][kk] = false;
			}
		
		int ans = 1;
		vis[x][y] = true;
		for(int j = 1; j <= k; j++)
		{
			if(d == 0)
			{
				if(1<=x&&x<=n&&1<=y+1&&y+1<=m && a[x][y+1] == '.')
				{
					y++;
					if(!vis[x][y]) ans++, vis[x][y] = true;
				}
				else d = (d+1)%4;
			}
			else if(d == 1)
			{
				if(1<=x+1&&x+1<=n&&1<=y&&y<=m && a[x+1][y] == '.')
				{
					x++;
					if(!vis[x][y]) ans++, vis[x][y] = true;
				}
				else d = (d+1)%4;
			}
			else if(d == 2)
			{
				if(1<=x&&x<=n&&1<=y-1&&y-1<=m && a[x][y-1] == '.')
				{
					y--;
					if(!vis[x][y]) ans++, vis[x][y] = true;
				}
				else d = (d+1)%4;
			}
			else if(d == 3)
			{
				if(1<=x-1&&x-1<=n&&1<=y&&y<=m && a[x-1][y] == '.')
				{
					x--;
					if(!vis[x][y]) ans++, vis[x][y] = true;
				}
				else d = (d+1)%4;
			}
		}
		cout << ans << endl;
	}
	return 0;
}