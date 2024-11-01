#include<iostream>
using namespace std;
int t,ans,x,y;
char ch[1050][1050];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int x0,y0,d0,n,m,k;
		cin >> n >> m >> k >> x0 >> y0 >> d0;
		ans = 1;
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= m; k++)
				cin >> ch[j][k];
		ch[x0][y0] = '0';
		for(int j = 0; j < k; j++)
		{
			x = x0,y = y0;
			if(d0 == 0)
				y++;
			else if(d0 == 1)
				x++;
			else if(d0 == 2)
				y--;
			else if(d0 == 3)
				x--;
			if(x < 1 || y < 1 || x > n || y > m || ch[x][y] == 'x')
				d0 = (d0 + 1) % 4;
			else
			{
				if(ch[x][y] != '0')
					ans++;
				ch[x][y] = '0';
				x0 = x,y0 = y;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
