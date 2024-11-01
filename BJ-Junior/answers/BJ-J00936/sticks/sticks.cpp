#include <bits/stdc++.h>
using namespace std;

int sum[10] = {6 , 2  , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};
int ans[100010];

int main()
{
	freopen("sticks.in" , "r" , stdin);
	freopen("sticks.out" , "w" , stdout);
	int T;
	cin >> T;
	while (T --)
	{
		int n;
		long long num = 1;
		cin >> n;
		if (n < 2)
		{
			cout << -1 << endl;
			continue;
		}
		if (n > 50)
		{
			if (n % 7 == 0)
			{
				int s = n / 7;
				while (s --) cout << 8;
				cout << endl;
				continue;
			}
			else
			{
				cout << 10;
				while (n > 10)
				{
					cout << 8;
					n -= 7;
				}
				cout << endl;
				continue;
			}
			continue;
		}
		if (ans[n] != 0)
		{
			cout << ans[n] << endl;
			continue;
		}
		while (num)
		{
			long long x = num;
			int s = 0;
			while (x)
			{
				s += sum[x % 10];
				x /= 10;
			}
			if (s == n)
			{
				cout << num << endl;
				ans[n] = num;
				break;
			}
			num ++;
		}
	}
	return 0;
}
