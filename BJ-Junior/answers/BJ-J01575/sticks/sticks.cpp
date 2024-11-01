#include <iostream>
#include <cstring>
#define int long long
using namespace std;

int t, n, num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int calc(int x)
{
	int res = 0;
	while(x > 0) res += num[x % 10], x /= 10;
	return res;
}

signed main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		int need8 = n / 7;
		int last = n % 7;
		if(last == 0)
		{
			for(int i = 1; i <= need8; i++)
				cout << 8;
			cout << endl;
		}
		else if(n == 1) cout << -1 << endl;
		else
		{
			for(int i = 1; i <= 8e5; i++)
				if(calc(i) == n)
				{
					cout << i << endl;
					goto finish;
				}
			cout << -1 << endl;
		}
		finish: ;
	}

	return 0;
}