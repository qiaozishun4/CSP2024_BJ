#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
string s;
char a[1003][1003] = {};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for(int z = 1;z <= t;z++)
	{
		memset(a,0,sizeof(a));
		cin >> n >> m >> k >> x >> y >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> s;
			for(int j = 0;j < m;j++)
			{
				a[i][j+1] = s[j];
			}
		}
		int ans = 1;
		for(int i = 1;i <= k;i++)
		{
			if(d == 0)
			{
				y++;
			}
			else if(d == 1)
			{
				x++;
			}
			else if(d == 2)
			{
				y--;
			}
			else
			{
				x--;
			}
			if(x <= n && y <= m && x >= 1 && y >= 1 && a[x][y] == '.')
			{
				ans++;
				a[x][y] = 'u';
			}
			else if(a[x][y] != 'u')
			{
				if(d == 0)
				{	
					y--;
				}
				else if(d == 1)
				{
					x--;
				}
				else if(d == 2)
				{
					y++;
				}
				else
				{
					x++;
				}
				d = d + 1;
				d %= 4;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
