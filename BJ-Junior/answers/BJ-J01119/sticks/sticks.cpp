#include <bits/stdc++.h>
using namespace std;

int c[100005];
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t, n;
	cin >> t;
	c[1] = -1;
	c[2] = 1;
	c[9] = 18;
	c[3] = 7;
	c[10] = 22;
	c[17] = 200;
	c[4] = 4;
	c[11] = 20;
	c[18] = 208;
	c[25] = 2088;
	c[5] = 2;
	c[12] = 28;
	c[19] = 288;
	c[26] = 2888;
	c[33] = 28888;
	c[6] = 6;
	c[13] = 68;
	c[20] = 688;
	c[27] = 6888;
	c[34] = 68888;
	c[41] = 688888;
	while (t--)
	{
		cin >> n;
		if (n % 7 == 0)
		{
			for (int i = 1; i <= n / 7; i++)
			{
				cout << 8;
			}
			cout << endl;
		}
		else if (n % 7 == 1 && n / 7 >= 1)
		{
			cout << 10;
			for (int i = 1; i <= n / 7 - 1; i++)
			{
				cout << 8;
			}
			cout << endl;
		}
		else if (n % 7 == 2 && n / 7 >= 2)
		{
			cout << 100;
			for (int i = 1; i <= n / 7 - 2; i++)
			{
				cout << 8;
			}
			cout << endl;
		}
		else if (n % 7 == 3 && n / 7 >= 3)
		{
			cout << 1000;
			for (int i = 1; i <= n / 7 - 3; i++)
			{
				cout << 8;
			}
			cout << endl;
		}
		else if (n % 7 == 4 && n / 7 >= 4)
		{
			cout << 10000;
			for (int i = 1; i <= n / 7 - 4; i++)
			{
				cout << 8;
			}
			cout << endl;
		}
		else if (n % 7 == 5 && n / 7 >= 5)
		{
			cout << 100000;
			for (int i = 1; i <= n / 7 - 5; i++)
			{
				cout << 8;
			}
			cout << endl;
		}
		else if (n % 7 == 6 && n / 7 >= 6)
		{
			cout << 1000000;
			for (int i = 1; i <= n / 7 - 6; i++)
			{
				cout << 8;
			}
			cout << endl;
		}
		cout << c[n] << endl;
	}
	return 0;
}
