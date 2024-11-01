#include <bits/stdc++.h>
using namespace std;

int t,n,m,k,f[1005][1005];
char a[1005][1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k;
		int x,y,d;
		cin >> x >> y >> d;
		memset(f,0,sizeof f);
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= m;j++)
			{
				cin >> a[i][j];
			}
		}
		f[x][y] = 1;
		for (int i = 1;i <= k;i++)
		{
			int nx = x,ny = y;
			if (d == 0) ny++;
			if (d == 1) nx++;
			if (d == 2) ny--;
			if (d == 3) nx--;
			if (nx < 1 || nx > n || ny < 1 || ny > m)
			{
				d = (d+1)%4;
				continue;
			}
			if (a[nx][ny] == 'x')
			{
				d = (d+1)%4;;
				continue;
			}
			f[nx][ny] = 1;
			x = nx,y = ny;
		}
		int ans = 0;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= m;j++)
			{
				if (f[i][j] == 1) ans++;
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}
