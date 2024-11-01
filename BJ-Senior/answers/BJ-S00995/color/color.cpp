#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5 + 5, M = 1e6 + 5;
const ll inf = 1e18;
int a[N];
ll ans[M];
ll sum[N], dp[N];

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t, n, m, i;
	ll mx;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		m = 0;
		for(i = 1; i <= n; i++)
		{
			scanf("%d", a + i);
			m = max(m, a[i]);
		}
		a[n + 1] = 0;
		for(i = 0; i <= m; i++)
			ans[i] = -inf;
		for(i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + (a[i] == a[i - 1] ? a[i] : 0);
		mx = 0;
		for(i = 2; i <= n + 1; i++)
		{
			dp[i] = sum[i - 1] + max(mx, a[i] + ans[a[i]]);
			mx = max(dp[i] - sum[i], mx);
			ans[a[i - 1]] = max(dp[i] - sum[i], ans[a[i - 1]]);
		}
		printf("%lld\n", dp[n + 1]);
	}
	return 0;
}