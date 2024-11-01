#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, num[N];
long long ans;
bool vis[N];
void Work (int i)
{
	if (i == n + 1)
	{
		long long tmp = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i - 1; j >= 1; j--)
			{
				if (vis[i] == vis[j])
				{
					if (num[j] == num[i])
						tmp += num[i];
					break;
				}
			}
		}
		ans = max (ans, tmp);
		return;
	}
	Work (i + 1);
	vis[i] = 1;
	Work (i + 1);
	vis[i] = 0;
	return;
}
int main ()
{
	freopen ("color.in", "r", stdin);
	freopen ("color.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> num[i];
		Work (1);
		cout << ans << endl;
	}
	return 0;
}