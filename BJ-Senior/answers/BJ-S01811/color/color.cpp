#include <iostream>
#include <cstdio>
using namespace std;

int a[110], ans;
bool color[110];

int point(int n)
{
	int lastr = 0, lastb = 0, pt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (color[i])
		{
			if (a[i] == a[lastr])
			{
				pt += a[i];
			}
			lastr = i;
		}
		else
		{
			if (a[i] == a[lastb])
			{
				pt += a[i];
			}
			lastb = i;
		}
	}
	return pt;
}

void s(int n, int num)
{
	if (num == n + 1)
	{
		ans = max(ans, point(n));
		return;
	}
	color[num] = false;
	s(n, num + 1);
	color[num] = true;
	s(n, num + 1);
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t, n;
	a[0] = -1;
	cin >> t;
	for (; t; t--)
	{
		cin >> n;
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		color[1] = true;
		s(n, 2);
		cout << ans << endl;
	}
	return 0;
}