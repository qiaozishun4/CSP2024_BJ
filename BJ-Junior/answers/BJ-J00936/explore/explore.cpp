#include <bits/stdc++.h>
using namespace std;

int dis[4][2] = {{0 , 1} , {1 , 0} , {0 , -1} , {-1 , 0}};
char mp[1005][1005];
bool go[1005][1005];

int main()
{
	freopen("explore.in" , "r" , stdin);
	freopen("explore.out" , "w" , stdout);
	int T;
	cin >> T;
	while (T --)
	{
		memset(go , 0 , sizeof(go));
		int n,m,k;
		cin >> n >> m >> k;
		int sx,sy,d,cnt = 0;
		cin >> sx >> sy >> d;
		go[sx][sy] = true;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				cin >> mp[i][j];
		while (k --)
		{
			int nx = sx + dis[d][0];
			int ny = sy + dis[d][1];
			if (nx < 1 || ny < 1 || nx > n || ny > m || mp[nx][ny] == 'x')
			{
				d ++;
				if (d == 4) d = 0;
				continue;
			}
			sx = nx;
			sy = ny;
			go[sx][sy] = true;
		}
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				cnt += go[i][j];
		cout << cnt << endl;
	}
	return 0;
}
