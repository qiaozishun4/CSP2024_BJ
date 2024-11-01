#include<bits/stdc++.h>
using namespace std;
char ch[1010][1010];
int visited[1010][1010];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
void Solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	memset(ch, 'x', sizeof(ch));
	memset(visited, 0, sizeof(visited));
	int x, y, d;
	cin >> x >> y >> d;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> ch[i][j];
		}
	}
	visited[x][y] = 1;
	while(k--)
	{
		if(ch[x + dx[d]][y + dy[d]] == 'x')
		{
			d = (d + 1) % 4;
		}
		else
		{
			x += dx[d];
			y += dy[d];
		}
		visited[x][y] = 1;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			ans += visited[i][j];
		}
	}
	cout << ans << endl;
}
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		Solve();
	}
	return 0;
}