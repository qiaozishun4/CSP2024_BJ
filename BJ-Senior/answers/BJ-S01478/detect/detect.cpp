#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
const int N = 1e5 + 5;
int n, m, pos, dp[N];
ll L, V, d[N], v0[N], a[N], p[N], p2[N];
struct node
{
	int l, r;
	bool operator<(const node t) const
	{
		return r < t.r;
	}
} range[N];
bool ill[N];
struct monoqueue
{
	int q[N], l = 1, r = 0;
	void init()
	{
		l = 1, r = 0;
	}
	void insert(int i)
	{
		while (l <= r && dp[q[r]] >= dp[i])
			r--;
		q[++r] = i;
	}
	int query(int key)
	{
		while (l <= r && q[l] < key)
			l++;
		return l <= r ? dp[q[l]] : inf;
	}
} q;

int my_lower(ll key, ll div)
{
	int l = 1, r = m, res = 0;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (p2[mid] * div > key)
		{
			res = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	return m + 1 - res;
}
int my_upper(ll key, ll div)
{
	int l = 1, r = m, res = m + 1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (p[mid] * div > key)
		{
			res = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	return res;
}


void solve()
{
	scanf("%d%d%lld%lld", &n, &m, &L, &V);
	for (int i = 1; i <= n; i++)
		scanf("%lld%lld%lld", d + i, v0 + i, a + i);
	for (int i = 1; i <= m; i++)
		scanf("%lld", p + i);
	sort(p + 1, p + m + 1);
	for (int i = 1; i <= m; i++)
		p2[i] = p[m - i + 1];
	pos = 0;
	for (int i = 1; i <= n; i++)
	{
		// int tmp = pos;
		int L = lower_bound(p + 1, p + m + 1, d[i]) - p, div = a[i] << 1;
		if (L > m)
			continue;
		if (a[i] == 0)
		{
			if (v0[i] > V)
				range[++pos] = {L, m};
		}
		else if (a[i] > 0)
		{
			if (v0[i] > V)
				range[++pos] = {L, m};
			else
			{
				range[++pos] = {max(L, my_upper(d[i] * div + V * V - v0[i] * v0[i], div)), m};
				// cout << "    " << d[i] * div + V * V - v0[i] * v0[i] << endl;
				if (range[pos].l > range[pos].r || range[pos].r == m + 1)
					pos--;
			}
		}
		else
		{
			if (v0[i] > V)
			{
				range[++pos] = {L, my_lower(d[i] * div + V * V - v0[i] * v0[i], div)};
				// if (i == 5)
				// {
				// 	cout << "    " << d[i] * div + V * V - v0[i] * v0[i] << endl;
				// 	cout << "    " << range[pos].l << ' ' << range[pos].r << endl;
				// }
				if (range[pos].l > range[pos].r || range[pos].r == m + 1)
					pos--;
			}
		}
		// if (pos > tmp)
		// 	cout << i << endl;
	}
	// for (int i = 1; i <= pos; i++)
	// {
	// 	cout << range[i].l << ' ' << range[i].r << endl;
	// }
	sort(range + 1, range + pos + 1);
	int it = 0, mx = 0;
	q.init();
	q.insert(0);
	for (int i = 1; i <= m; i++)
	{
		dp[i] = inf;
		while (it < pos && range[it + 1].r < i)
			mx = max(mx, range[++it].l);
		dp[i] = q.query(mx) + 1;
		q.insert(i);
		// cout << dp[i] << " \n"[i == m];
	}
	while (it < pos)
		mx = max(mx, range[++it].l);
	// cout << "    " << mx << endl << "    ";
	// for (int i = q.l; i <= q.r; i++)
	// 	cout << q.q[i] << " \n"[i == q.r];
	printf("%d %d\n", pos, m - q.query(mx));
}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}