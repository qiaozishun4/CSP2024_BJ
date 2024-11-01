#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct car
{
	int x, v, a;
	double b;
};

struct qj
{
	int l, r;
};

const int N = 100010;
car c[N];
vector<car> cs;
qj cq[N];
int d[N], tcnt, ud;
bool vis[N];

bool bmp(qj a, qj b)
{
	return a.r < b.r;
}

bool chk(int num)
{
	for (int i = cq[num].l; i <= cq[num].r; i++)
	{
		if (vis[i])
		{
			return true;
		}
	}
	return false;
}

int last(int m, double num)
{
	int l = 1, r = m, mid;
	while (l < r)
	{
		mid = (l + r) / 2;
		if (num > d[mid])
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	if (num >= d[l])
	{
		l++;
	}
	return l - 1;
}

int ef(int sz, int fd)
{
	int l = 0, r = sz - 1, mid;
	while (l < r)
	{
		mid = (l + r) / 2;
		if (fd > cq[mid].r)
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	return l;
}

void ans(int m, int num, int cnt)
{
	if (cnt >= tcnt)
	{
		return;
	}
	int x = ef(cs.size(), num);
	for (int i = x; num == cq[i].r; i++)
	{
		if (!chk(i))
		{
			vis[num] = true;
			break;
		}
	}
	cnt += vis[num];
	if (num == m)
	{
		tcnt = cnt;
		vis[num] = false;
		return;
	}
	ans(m, num + 1, cnt);
	if (!vis[num])
	{
		vis[num] = true;
		ans(m, num + 1, cnt + 1);
	}
	vis[num] = false;
}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int n, m, t, l, k;
	cin >> t;
	vis[0] = true;
	for (; t; t--)
	{
		cin >> n >> m >> l >> k;
		cs.clear();
		for (int i = 1; i <= n; i++)
		{
			cin >> c[i].x >> c[i].v >> c[i].a;
			if (c[i].a > 0)
			{
				c[i].b = (c[i].v > k) ? c[i].x : c[i].x + (c[i].v + k) * (k - c[i].v) / 2.0 / c[i].a;
			}
			else if (c[i].a < 0)
			{
				c[i].b = (c[i].v > k) ? c[i].x + (c[i].v + k) * (k - c[i].v) / 2.0 / c[i].a : 0;
				if (c[i].b > l)
				{
					c[i].b = l;
				}
			}
			else
			{
				c[i].b = (c[i].v > k) ? c[i].x : 0;
			}
			//cout << endl << c[i].x << " " << c[i].b;
			if (c[i].b > 0 && c[i].b <= l)
			{
				cs.push_back(c[i]);
			}
		}
		//cout << endl;
		tcnt = m;
		ud = 0;
		for (int i = 1; i <= m; i++)
		{
			cin >> d[i];
			vis[i] = false;
		}
		qj q;
		for (int i = 0; i < cs.size(); i++)
		{
			if (cs[i].a < 0)
			{
				q.l = last(m, (double)cs[i].x);
				q.r = last(m, cs[i].b);
			}
			else if (cs[i].a > 0)
			{
				q.l = last(m, cs[i].b);
				q.r = m;
			}
			else
			{
				q.l = last(m, (double)cs[i].x);
				q.r = m;
			}
			q.l += (d[q.l] != cs[i].x);
			//cout << q.l << " " << q.r << endl;
			if (q.r < q.l)
			{
				ud++;
				q.l = 0;
			}
			cq[i] = q;
		}
		sort(cq, cq + cs.size(), bmp);
		ans(m, 1, 0);
		cout << cs.size() - ud << " " << m - tcnt << endl;
	}
	return 0;
}