#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int t, n, m, l, v, ans, stan, p[100005];
bool flag34, flag56, vis[100005], chk[100005];
struct node
{
	int d, v, a;
} c[100005];

int calc()
{
	memset(chk, false, sizeof chk);
	int res = 0;
	for(int i = 1; i <= m; i++)
		if(vis[i])
			for(int j = 1; j <= n; j++)
				if(p[i] >= c[j].d)
				{
					double v_now = sqrt(max(0.0, 1.0 * c[j].v * c[j].v + 2.0 * c[j].a * (p[i] - c[j].d)));
					if(v_now > v)
						chk[j] = true;
				}
	for(int i = 1; i <= n; i++)
		if(chk[i])
			res++;
	return res;
}
void dfs(int x, int tmp)
{
	if(x == m + 1)
	{
		if(calc() == stan)
			ans = max(ans, tmp);
		return ;
	}
	vis[x] = true, dfs(x + 1, tmp);
	vis[x] = false, dfs(x + 1, tmp + 1);
	return ;
}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> l >> v, flag34 = true, flag56 = true;
		for(int i = 1; i <= n; i++)
			cin >> c[i].d >> c[i].v >> c[i].a;
		for(int i = 1; i <= m; i++)
			cin >> p[i];
		for(int i = 1; i <= n; i++)
			if(c[i].a)
			{
				flag34 = false;
				break;
			}
		for(int i = 1; i >= n; i++)
			if(c[i].a <= 0)
			{
				flag56 = false;
				break;
			}
		if(flag34)
		{
			int lastp = 0, cnt = 0;
			for(int i = 1; i <= m; i++)
				lastp = max(lastp, p[i]);
			for(int i = 1; i <= n; i++)
				if(c[i].d <= lastp && c[i].v > v)
					cnt++;
			cout << cnt << ' ';
			int firstd = l + 1;
			for(int i = 1; i <= n; i++)
				if(c[i].d <= lastp && c[i].v > v)
					firstd = min(firstd, c[i].d);
			int l = 1, r = m, ans;
			while(l < r)
			{
				int mid = l + r >> 1;
				if(p[mid] < firstd) ans = mid, l = mid + 1;
				else r = mid - 1;
			}
			if(cnt == 0) cout << m << endl;
			else cout << m - 1 << endl;
		}
		else if(flag56)
		{
			ans = 0;
			for(int i = 1; i <= n; i++)
				if(p[m] >= c[i].d)
				{
					double v_new = sqrt(1.0 * c[i].v * c[i].v + 2.0 * c[i].a * (p[m] - c[i].d));
					if(v_new > v) ans++;
				}
			if(ans) cout << ans << ' ' << m - 1 << endl;
			else cout << ans << ' ' << m << endl;
		}
		else
		{
			memset(vis, true, sizeof vis), stan = calc();
			cout << stan << ' ';
			ans = 0, dfs(1, 0);
			cout << ans << endl;
		}
	}

	return 0;
}