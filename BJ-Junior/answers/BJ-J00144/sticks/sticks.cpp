#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int num_stick[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int T, n, ans[N];
int main ()
{
	freopen ("sticks.in", "r", stdin);
	freopen ("sticks.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		cin >> n;
		if (n == 1 || n == 0)
		{
			cout << -1 << endl;
			continue;
		}
		else if (n % 7 == 1)
		{
			cout << 10;
			n -= 8;
		}
		else if (n % 7 == 2)
		{
			cout << 1;
			n -= 2;
		}
		else if (n % 7 == 3)
		{
			if (n == 3)
			{
				cout << 7 << endl;
				continue;
			}
			else
			{
				cout << 34;
				n -= 10;
			}
		}
		else if (n % 7 == 4)
		{
			if (n == 4)
			{
				cout << 4 << endl;
				continue;
			}
			else
			{
				cout << 20;
				n -= 11;
			}
		}
		else if (n % 7 == 5)
		{
			cout << 2;
			n -= 5;
		}
		else if (n % 7 == 6)
		{
			if (n == 6)
			{
				cout << 6 << endl;
				continue;
			}
			else
			{
				cout << 80;
				n -= 13;
			}
		}
		if (n)
			for (int i = 1; i <= n; i += 7)
				cout << 8;
		cout << endl;
	}
	return 0;
}