#include <bits/stdc++.h>

using namespace std;

char a[1005][1005];
bool b[1005][1005] = {false};

int ans[5];

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	int t;
	cin >> t;
	
	for (int u = 0; u < t; u ++ )
	{
		
		int n, m, k, x, y, d, ans = 0;
		cin >> n >> m >> k >> x >> y >> d;
		
		x -= 1;
		y -= 1;
		
		b[x][y] = true;
		
		for (int i = 0; i < n; i ++ )
		{
			for (int j = 0; j < m; j ++ )
			{
				cin >> a[i][j];
			}
		}
		
		for (int i = 0; i < k; i ++ )
		{
			if (d == 0)
			{
				if (a[x][y + 1] == '.' && y + 1 < m)
				{
					b[x][y + 1] = true;
					y += 1;
				}
				else d = (d + 1) % 4;
			}
			else if (d == 1)
			{
				if (a[x + 1][y] == '.' && x + 1 < n)
				{
					b[x + 1][y] = true;
					x += 1;
				}
				else d = (d + 1) % 4;
			}
			else if (d == 2)
			{
				if (a[x][y - 1] == '.' && y - 1 >= 0)
				{
					b[x][y - 1] = true;
					y -= 1;
				}
				else d = (d + 1) % 4;
			}
			else if (d == 3)
			{
				if (a[x - 1][y] == '.' && x - 1 >= 0)
				{
					b[x - 1][y] = true;
					x -= 1;
				}
				else d = (d + 1) % 4;
			}
		}
		
		for (int i = 0; i < n; i ++ )
		{
			for (int j = 0; j < m; j ++ )
			{
				if (b[i][j] == true) ans ++ ;
			}
		}
		
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
