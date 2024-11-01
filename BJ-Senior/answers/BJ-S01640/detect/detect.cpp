#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int t;
int n, m, l, v;
int dd[N], vv[N], aa[N];
int p[N], maxp;
int ans;

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d%d", &n, &m, &l, &v);
		for (int i = 0; i < n; i++)
			scanf("%d%d%d", &dd[i], &vv[i], &aa[i]);
		for (int i = 0; i < m; i++)
			scanf("%d", &p[i]), maxp = max(maxp, p[i]);
		for (int i = 0; i < n; i++)
			if (aa[i] == 0)
			{
				if (vv[i] > v && dd[i] <= maxp)
					ans++;
			}
			else
			{
				if (dd[i] <= maxp && sqrt((double) vv[i] * vv[i] + 2.0 * aa[i] * (maxp - dd[i])) > (double) v)
					ans++;
			}
		if (!ans)
			printf("0 %d\n", m);
		else
			printf("%d %d\n", ans, m - 1);
		ans = maxp = 0;
	}

	return 0;
}