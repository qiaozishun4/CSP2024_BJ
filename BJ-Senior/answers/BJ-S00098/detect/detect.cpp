#include<bits/stdc++.h>
using namespace std;
#define int long long
int d[100005], v[100005], a[100005], p[100005], st[100005], en[100005];
bool vis[100005], Vis[100005], book[100005];
int ans, n, m, l, V;
void dfs(int id, int tot)
{
	if(id > m)
	{
		ans = max(ans, tot);
		return;
	}
	dfs(id + 1, tot);
	book[id] = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(!vis[i]) continue;
		for(int j = st[i]; j <= en[i]; j ++)
		{
			if(book[j])
			{
				break;
			}
			if(j == en[i])
			{
				book[id] = 1;
				return;
			}
		}
	}
	dfs(id + 1, tot + 1);
}
signed main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	cin >> t;
	while(t --)
	{
		memset(vis, 0, sizeof(vis));
		cin >> n >> m >> l >> V;
		bool flag = 0;
		for(int i = 1; i <= n; i ++)
		{
			cin >> d[i] >> v[i] >> a[i];
			if(a[i] < 0) flag = 1;
		}
		for(int i = 1; i <= m; i ++)
		{
			cin >> p[i];
		}
		if(flag)
		{
			memset(st, 0x3f, sizeof(st));
			memset(en, 0, sizeof(en));
			for(int i = 1; i <= n; i ++)
			{
				for(int j = 1; j <= m; j ++)
				{
					if(p[j] < d[i]) continue;
					if(V * V < v[i] * v[i] + 2 * a[i] * (p[j] - d[i]))
					{
						vis[i] = 1;
						st[i] = min(st[i], j);
						en[i] = max(en[i], j);
					}
				}
			}
			ans = 0;
			for(int i = 1; i <= n; i ++)
			{
				if(vis[i]) ans ++;
			}
			cout << ans << ' ';
			ans = 0;
			for(int i = 1; i <= m; i ++) book[i] = 1;
			dfs(1, 0);
			cout << ans << endl;
		}
		else
		{
			for(int i = 1; i <= n; i ++)
			{
				if(a[i] >= 0)
				{
					if(p[m] < d[i]) continue;
					if(V * V < v[i] * v[i] + 2 * a[i] * (p[m] - d[i]))
					{
						vis[i] = 1;
					}
				}
				else
				{
					int j = 1;
					while(p[j] < d[i])
					{
						if(j == m) goto ne;
						j ++;
					}
					if(V * V < v[i] * v[i] + 2 * a[i] * (p[j] - d[i]))
					{
						vis[i] = 1;
					}
				}
				ne:;
			}
			ans = 0;
			for(int i = 1; i <= n; i ++)
			{
				if(vis[i]) ans ++;
			}
			cout << ans << ' ';
			if(ans > 0)
			{
				cout << m - 1 << endl;
			}
			else
			{
				cout << m << endl;
			}
		}
	}
	return 0;
}
