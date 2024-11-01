#include <bits/stdc++.h>
using namespace std;

int n;

const int N = 1e3 + 10;

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int p,q,sum,x,y,ntw,answer = 0;
		cin >> p >> q >> sum >> x >> y >> ntw;
		char a[N][N],used[N][N] = {0};
		for (int j = 1;j <= p;j++)
		{
			for (int k = 1;k <= q;k++)
			{
				cin >> a[j][k];
			}
		}
		while(sum > 0)
		{
			if (used[x][y] == 0)
			{
				answer++;
				used[x][y] = 1;
			}
			if (ntw == 0 && y + 1 <= q && a[x][y + 1] == '.')
			{
				sum--;
				y++;
			}
			else if (ntw == 0)
			{
				sum--;
				ntw = 1;
			}
			else if (ntw == 1 && x + 1 <= p && a[x + 1][y] == '.')
			{
				sum--;
				x++;
			}
			else if (ntw == 1)
			{
				sum--;
				ntw = 2;
			}
			else if (ntw == 2 && y - 1 >= 1 && a[x][y - 1] == '.')
			{
				sum--;
				y--;
			}
			else if (ntw == 2)
			{
				sum--;
				ntw = 3;
			}
			else if (ntw == 3 && x - 1 >= 1 && a[x - 1][y] == '.')
			{
				sum--;
				x--;
			}
			else if (ntw == 3)
			{
				sum--;
				ntw = 0;
			}
		}
		if (used[x][y] == 0)
		{
			answer++;
			used[x][y] = 1;
		}
		cout << answer << endl;
	}
	return 0;
}