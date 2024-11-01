#include <bits/stdc++.h>
using namespace std;

struct car
{
	int d, v, a;
}c[100005];
int w[100005], vis[100005], bx[100005];
int maxn, n, m, cnt;
double vl;
void dfs(int cur)
{
	if (cur > m)
	{
		int ls = 0;
		memset(vis, 0, sizeof(vis));
//		for (int i = 1; i <= n; i++)
//		{
//			cout << bx[i] << " ";
//		}
//		cout << endl;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (bx[j] == 1) continue;
				if (c[i].v * c[i].v + 2 * c[i].a * (w[j] - c[i].d) < 0) continue;
				if (w[j] >= c[i].d && sqrt(c[i].v * c[i].v + 2 * c[i].a * (w[j] - c[i].d)) > vl)
				{
					vis[i] = 1;
				}
			}
		}
		for (int i = 1; i <= m; i++)
		{
			if (bx[i] == 1)
			{
				ls++;
			}
		}
		int cnt2 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (vis[i])
			{
				cnt2++;
			}
		}
		if (cnt2 == cnt)
		{
			maxn = max(maxn, ls);
		}
		return;
	}
	for (int i = 1; i <= 2; i++)
	{
		if (i == 1)
		{
			bx[cur] = 1;
		}
		else if (i == 2)
		{
			bx[cur] = 2;
		}
		dfs(cur + 1);
		bx[cur] = 0;
	}
}
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t, l;
	cin >> t;
	while (t--)
	{
		memset(vis, 0, sizeof(vis));
		memset(bx, 0, sizeof(bx));
		maxn = 0;
		cnt = 0;
		cin >> n >> m >> l >> vl;
		for (int i = 1; i <= n; i++)
		{
			cin >> c[i].d >> c[i].v >> c[i].a;
		}
		for (int i = 1; i <= m; i++)
		{
			cin >> w[i];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (w[j] >= c[i].d && sqrt(c[i].v * c[i].v + 2 * c[i].a * (w[j] - c[i].d)) > vl)
				{
					vis[i] = 1;
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (vis[i]) cnt++;
		}
		dfs(1);
		cout << cnt << " " << maxn << endl;
	}
	return 0;
}
