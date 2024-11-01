#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char a[N][N];
bool vis[N][N];
int n , m , k , sx , sy , sd , cnt = 0;
int dx[5] = {0 , 1 , 0 , -1};
int dy[5] = {1 , 0 , -1 , 0};
void Solve(int x , int y , int d)
{
	int step = 1 , cnt = 1;
	while(step <= k)
	{
		int nx = x + dx[d];
		int ny = y + dy[d];
		if(1 <= nx && nx <= n && 1 <= ny && ny <= m && a[nx][ny] == '.') 
		{
			if(!vis[nx][ny]) 
			{
				// cout << " true";
				cnt++;
				vis[nx][ny] = 1;
			}
			// cout << endl;
			step++;
			x = nx;
			y = ny;
		}
		else 
		{
			// cout << endl;
			step++;
			d = (d + 1) % 4;
		}
	}
	cout << cnt << endl;
}
int main()
{
	freopen("explore.in" , "r" , stdin);
	freopen("explore.out" , "w" , stdout);
	int T;
	cin >> T;
	while(T--)
	{
		// cout << T << ":" << endl;
		memset(vis , 0 , sizeof(vis));
		cin >> n >> m >> k >> sx >> sy >> sd;
		vis[sx][sy] = 1;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				cin >> a[i][j];
			}
		}
		Solve(sx , sy , sd);
	}
	return 0;
}