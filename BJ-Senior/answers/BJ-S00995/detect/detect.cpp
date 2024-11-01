#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 1e6 + 5;
int d[N], v[N], a[N];
int p[N], lst[N], dp[N];

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t, n, m, L, V, i, x, y, c;
	int l, r;
	scanf("%d", &t);
	while(t--)
	{
		c = 0;
		scanf("%d%d%d%d", &n, &m, &L, &V);
		for(i = 1; i <= n; i++)
			scanf("%d%d%d", d + i, v + i, a + i);
		for(i = 1; i <= m; i++)
			scanf("%d", p + i);
		for(i = 1; i <= m + 1; i++)
			lst[i] = 0;
		for(i = 1; i <= n; i++)
		{
			if(v[i] <= V && a[i] <= 0)
				continue;
			x = lower_bound(p + 1, p + m + 1, d[i]) - p;
			if(x > m)
				continue;
			if(a[i] == 0)
			{
				l = x;
				r = m;
				// printf("A%d: %d %d\n", i, l, r);
				++c;
				lst[r] = max(lst[r], l);
				continue;
			}
			if(a[i] < 0)
			{
				l = x;
				y = d[i] + (v[i] * v[i] - V * V - 1) / (-2 * a[i]);
				r = upper_bound(p + 1, p + m + 1, y) - p - 1;
				// printf("B%d: %d %d\n", i, l, r);
				if(l <= r)
				{
					++c;
					lst[r] = max(lst[r], l);
				}
				continue;
			}
			if(v[i] <= V)
				y = d[i] + (V * V - v[i] * v[i]) / (2 * a[i]);
			else
				y = d[i] - 1;
			l = upper_bound(p + 1, p + m + 1, y) - p;
			r = m;
			// printf("C%d: %d %d\n", i, l, r);
			if(l <= r)
			{
				++c;
				lst[r] = max(lst[r], l);
			}
		}
		for(i = 1; i <= m; i++)
		{
			lst[i] = max(lst[i - 1], lst[i]);
			dp[i] = dp[lst[i - 1]] + 1;
		}
		printf("%d %d\n", c, m - dp[lst[m]]);
	}
	return 0;
}