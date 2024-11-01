#include <bits/stdc++.h>
using namespace std;
int n,m,k,sx,sy,d;
char a[1005][1005];
bool vis[1005][1005];
void solve()
{
	cin >> n >> m >> k;
	cin >> sx >> sy >> d;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) 
		{
			cin >> a[i][j];
			vis[i][j] = 0;
		}
	}
	vis[sx][sy] = 1;
	for(int i=1;i<=k;i++)
	{
		if(d == 0)
		{
			if(sy==m || a[sx][sy+1] == 'x') d = (d + 1) % 4;
			else
			{
				sy ++;
				vis[sx][sy] = 1;
			}
		}
		else if(d == 1)
		{
			if(sx==n || a[sx+1][sy] == 'x') d = (d + 1) % 4;
			else
			{
				sx ++;
				vis[sx][sy] = 1;
			}
		}
		else if(d == 2)
		{
			if(sy==1 || a[sx][sy-1] == 'x') d = (d + 1) % 4;
			else
			{
				sy --;
				vis[sx][sy] = 1;
			}
		}
		else if(d == 3)
		{
			if(sx==1 || a[sx-1][sy] == 'x') d = (d + 1) % 4;
			else
			{
				sx --;
				vis[sx][sy] = 1;
			}
		}
	}
	int cnt = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) if(vis[i][j]) {cnt ++;}
	}
	cout << cnt << "\n";
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T ;
	while(T--) solve();
}