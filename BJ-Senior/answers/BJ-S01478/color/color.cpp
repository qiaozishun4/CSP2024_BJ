#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, a[N];
ll dp[2][2][N], ans;

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	memset(dp[0], 0, sizeof(dp[0]));
	for (int i = 1, cur = 1; i <= n; i++, cur ^= 1)
	{
		for (int j = 0; j <= i; j++)
			dp[cur][0][j] = dp[cur][1][j] = 0;
		for (int k = 0; k <= 1; k++)
			for (int j = 0; j < i - 1; j++) // where is the last color diff to a[i - 1]
			{
				dp[cur][k][j] = max(dp[cur][k][j], dp[cur ^ 1][k][j] + (a[i] == a[i - 1]) * a[i]);
				dp[cur][k][i - 1] = max(dp[cur][k][i - 1], dp[cur ^ 1][k ^ 1][j] + (a[i] == a[j]) * a[i]);
			}
	}
	ans = 0;
	for (int i = 0; i <= n; i++)
		ans = max(ans, max(dp[n & 1][0][i], dp[n & 1][1][i]));
	printf("%lld\n", ans);
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}