#include <iostream>
#include <algorithm>
using namespace std;

int n, a[200005], x[200005], t, bpos, rpos;
bool f[20];
long long ans, sum;

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (n <= 15)
		{
			ans = 0;
			for (int k = 0; k <= ((1 << n) - 1); k++)
			{
				bpos = 0, rpos = 0;
				sum = 0;
				for (int i = 1; i <= n; i++)
				{
					if ((k & (1 << (i - 1))) == 0)
					{
						if (a[bpos] == a[i]) sum += a[i];
						bpos = i;
					}
					else
					{
						if (a[rpos] == a[i]) sum += a[i];
						rpos = i;
					}
				}
				ans = max(ans, sum);
			}
			cout << ans << endl;
		}
	}
	
	return 0;
}