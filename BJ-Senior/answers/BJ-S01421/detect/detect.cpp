#include <iostream>
#include <algorithm>

#define ld long double
#define eps 1e-6

using namespace std;

const int maxn = 1e6 + 10;

int T;
int n, m;
ld L, V;
ld d[maxn], v[maxn], a[maxn];
ld pos[maxn];
int cnt, tot;
struct Node
{
	ld fst, scd;
} ovsp[maxn], ovsp2[maxn];

struct node
{
	int l, r;
	int tag, tag2;
	int mx;
} t[maxn << 2];
void update(int rt) { t[rt].mx = max(t[rt << 1].mx, t[rt << 1 | 1].mx); }
void build(int rt, int l, int r)
{
	t[rt].l = l, t[rt].r = r, t[rt].mx = 0, t[rt].tag = 0, t[rt].tag2 = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid); build(rt << 1 | 1, mid + 1, r);
	update(rt);
}
void pushdown(int rt)
{
	if (t[rt].tag2)
	{
		t[rt << 1].mx = 0, t[rt << 1 | 1].mx = 0;
		t[rt << 1].tag = t[rt << 1 | 1].tag = 0;
		t[rt << 1].tag2 = 1, t[rt << 1 | 1].tag2 = 1;
		t[rt].tag2 = 0;
	}
	if (t[rt].tag)
	{
		t[rt << 1].mx = (t[rt << 1].mx + t[rt].tag) * !t[rt].tag2;
		t[rt << 1 | 1].mx = (t[rt << 1 | 1].mx + t[rt].tag) * !t[rt].tag2;
		(t[rt << 1].tag += t[rt].tag) *= !t[rt].tag2;
		(t[rt << 1 | 1].tag += t[rt].tag) *= !t[rt].tag2;
		t[rt].tag = 0;
	}
	
}
void add(int rt, int l, int r)
{
	if (t[rt].l > r || t[rt].r < l) return;
	if (t[rt].l >= l && t[rt].r <= r) 
	{
		t[rt].mx++;
		t[rt].tag++;
		return;
	}
	pushdown(rt);
	add(rt << 1, l, r), add(rt << 1 | 1, l, r);
	update(rt);
}
void del(int rt, int l, int r)
{
	if (t[rt].l > r || t[rt].r < l) return;
	if (t[rt].l >= l && t[rt].r <= r) 
	{
		t[rt].mx = 0;
		t[rt].tag = 0;
		t[rt].tag2 = 1;
		return;
	}
	pushdown(rt);
	del(rt << 1, l, r), del(rt << 1 | 1, l, r);
	update(rt);
}
int query(int rt, int l, int r)
{
	if (t[rt].l > r || t[rt].r < l) return 0;
	if (t[rt].l >= l && t[rt].r <= r) return t[rt].mx;
	pushdown(rt);
	return max(query(rt << 1 | 1, l, r), query(rt << 1, l, r));
}

void init() { cnt = tot = 0; }

void solve()
{
	cin >> n >> m;
	cin >> L >> V;
	init();
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i] >> v[i] >> a[i];
		if (a[i] == 0)
		{
			if (v[i] > V) ovsp[++cnt] = { d[i], L };
		}
		else
		{
			if (a[i] < 0)
			{
				if (v[i] <= V) continue;
				ld s = (V * V - v[i] * v[i]) / (2.0 * a[i]);
				ovsp[++cnt] = { d[i], min(L, d[i] + s - eps) };
			}
			else
			{
				if (v[i] > V) { ovsp[++cnt] = { d[i], L }; continue; }
				ld s = (V * V - v[i] * v[i]) / (2.0 * a[i]);
				if (d[i] + s > L) continue;
				ovsp[++cnt] = { d[i] + s + eps, L };
			}
		}
		// printf("%d %.6Lf %.6Lf\n" , cnt, ovsp[i].fst, ovsp[i].scd);
	}	
	// cout << cnt << "\n";
	for (int i = 1; i <= m; i++)
		cin >> pos[i];
	sort(pos + 1, pos + m + 1);
	for (int i = 1; i <= cnt; i++)
	{
		int l = 1, r = m, res1 = -1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (pos[mid] >= ovsp[i].fst) r = mid - 1, res1 = mid;
			else l = mid + 1;
		}
		int l1 = 1, r1 = m;
		int res2 = -1;
		while (l1 <= r1)
		{
			int mid = (l1 + r1) / 2;
			if (pos[mid] <= ovsp[i].scd) l1 = mid + 1, res2 = mid;
			else r1 = mid - 1;
		}
		// printf("%.6Lf %.6Lf %.6Lf %.6Lf\n" , ovsp[i].fst, ovsp[i].scd, pos[res1], pos[res2]);
		if ((res1 == -1 && res2 == -1) || (res1 > res2)) continue;
		ovsp2[++tot] = { 1.0 * res1, 1.0 * res2 };
		// printf("%.6Lf %.6Lf %.6Lf %.6Lf\n" , ovsp[i].fst, ovsp[i].scd, pos[res1], pos[res2]);
	}
	cout << tot << " ";
	sort(ovsp2 + 1, ovsp2 + tot + 1, [](const Node& x, const Node& y){
		if (x.fst != y.fst) return x.fst < y.fst;
		return x.scd < y.scd;
	});
	int num = 0, ans = 0, mxr = 0;
	build(1, 1, m);
	for (int i = 1; i <= tot; i++)
	{
		++num;
		add(1, (int)ovsp2[i].fst, (int)ovsp2[i].scd);
		// cout << (int)ovsp2[i].fst << " " << (int)ovsp2[i].scd << "\n";
		mxr = max(mxr, (int)ovsp2[i].scd);
		// for (int j = 1; j <= mxr; j++) cout << query(1, j, j) << " "; 
		// cout << "\n";
		int tmp = query(1, (int)ovsp2[i].fst, (int)ovsp2[i].scd);
		// cout << tmp << " " << num << "qwq" << "\n";
		if (tmp != num)
		{
			ans++;
			if (m * m <= 4e8)
				build(1, 1, m);
			else del(1, 1, mxr);
			num = 1;
			add(1, (int)ovsp2[i].fst, (int)ovsp2[i].scd);
		}
	}
	if (num) ans++;
	cout << m - ans << "\n";
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);

	cin >> T;
	while (T--) solve();
	return 0;
}