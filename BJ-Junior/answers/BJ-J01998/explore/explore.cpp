#include <iostream>
using namespace std;

int a[1005][1005];
bool b[1005][1005];
int ans[10];
int moni(int n,int m,int k,int x,int y,int d)
{
	int cnt = 1;
	b[x][y] = 1;
	for (int j = 1;j <= k;j++)
	{
		int x1,y1;
		if (d == 0)
		{
			x1 = x;
			y1 = y+1;
		}
		if (d == 1)
		{
			x1 = x+1;
			y1 = y;
		}
		if (d == 2)
		{
			x1 = x;
			y1 = y-1;
		}
		if (d == 3)
		{
			x1 = x-1;
			y1 = y;
		}
		if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && a[x1][y1] == 2)
		{
			x = x1;
			y = y1;
			if (b[x][y] == 0)
			{
				cnt++;
				b[x][y] = 1;
			}
		}
		else
		{
			d = (d+1) % 4;
		}
	}
	for (int j = 1;j <= n;j++)
	{
		for (int l = 1;l <= m;l++)
		{
			a[j][l] = 0;
			b[j][l] = 0;
		}
	}
	return cnt;
}	

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	for (int i = 1;i <= T;i++)
	{
		int n,m,k,x,y,d;
		cin >> n >> m >> k >> x >> y >> d;
		for (int j = 1;j <= n;j++)
		{
			for (int l = 1;l <= m;l++)
			{
				char r;
				cin >> r;
				if (r == '.')
				{
					a[j][l] = 2;
				}
				else
				{
					a[j][l] = 1;
				}
			}
		}
		ans[i] = moni(n,m,k,x,y,d);
	}
	for (int i = 1;i <= T;i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}