#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n , m , k , sx , sy , d;
char mp[N][N];
int cnt;
bool f = 0 , vis[N][N];
void dfs(int x , int y , int cur)
{
	if(f == true)
	{
		return;
	}
	if(cur == k + 1)
	{
		f = true;
		return;
	}
	int nx , ny;
	if(d == 0)
	{
		nx = x , ny = y + 1;
	}
	else if(d == 1)
	{
		nx = x + 1 , ny = y;
	}
	else if(d == 2)
	{
		nx = x , ny = y - 1;
	}
	else if(d == 3)
	{
		nx = x - 1 , ny = y;
	}
	if(nx < 1 || nx > n || ny < 1 || ny > m || mp[nx][ny] == 'x')
	{
		d = (d + 1) % 4;
		dfs(x , y , cur + 1);
		if(f == true)
		{
			return;
		}
	}
	else if(mp[nx][ny] == '.')
	{
		if(vis[nx][ny] == 0)
		{
			cnt++;
		}
		vis[nx][ny] = 1;
		dfs(nx , ny , cur + 1);
		if(f == true)
		{
			return;
		}
	}
}
int main()
{
	freopen("explore.in" , "r" , stdin);
	freopen("explore.out" , "w" , stdout);
	int T;
	cin >> T;
	while(T--)
	{
		memset(vis , 0 , sizeof(vis));
		cin >> n >> m >> k;
		cin >> sx >> sy >> d;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				cin >> mp[i][j];
			}
		}
		if(k == 1)
		{
			int nx , ny;
			if(d == 0)
			{
				nx = sx , ny = sy + 1;
			}
			if(d == 1)
			{
				nx = sx + 1 , ny = sy;
			}
			if(d == 2)
			{
				nx = sx , ny = sy - 1;
			}
			if(d == 3)
			{
				nx = sx - 1 , ny = sy;
			}
			if(nx < 1 || nx > n || ny < 1 || ny > n)
			{
				cout << 1 << endl;
				continue;
			}
			if(mp[nx][ny] == 'x')
			{
				cout << 1 << endl;
				continue;
			}
			cout << 2 << endl;
			continue;
		}
		vis[sx][sy] = 1;
		dfs(sx , sy , 1);
		cout << cnt + 1 << endl;
		cnt = f = 0;
	}
	return 0;
}
