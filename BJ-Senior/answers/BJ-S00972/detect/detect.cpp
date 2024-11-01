#include<bits/stdc++.h>
using namespace std;
typedef long double ldb;
const int N = 100005;
const ldb Exp = 1e-8;

int T, n, m, l, v, p, cur, cnt, flg;
struct car {int d, vl, ac, ct, gt, ot; } c[N]; bool cmp1(car a, car b) {return a.gt < b.gt; }
struct tst {int tot; vector<int> cv; } t[N]; bool cmp2(tst a, tst b) {return a.tot < b.tot; }
ldb calc(int v0, int v1, int acc) {return (v1 * v1 * 1.0 - v0 * v0 * 1.0) / 2.0 / acc; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	cin >> T;
	while(T--)
	{
		cin >> n >> m >> l >> v;
		for(int i = 1; i <= n; i++)
		{
			cin >> c[i].d >> c[i].vl >> c[i].ac; c[i].ct = 0;
			if(!c[i].ac) {if(c[i].vl <= v) i--, n--; else c[i].gt = c[i].d, c[i].ot = l; }
			else if(c[i].ac > 0)
				c[i].gt = c[i].d + (c[i].vl <= v) * ceil(calc(c[i].vl, v, c[i].ac) + Exp), c[i].ot = l;
			else if(c[i].ac < 0 && c[i].vl <= v) i--, n--;
			else c[i].gt = c[i].d, c[i].ot = c[i].d + floor(calc(v, c[i].vl, -1 * c[i].ac) - Exp);
		}
		sort(c + 1, c + n + 1, cmp1); cur = 1, cnt = 0;
		for(int i = 1; i <= m; i++)
		{
			cin >> p; t[i].tot = 0, t[i].cv.clear(); while(c[cur].gt <= p && cur <= n) cur++;
			for(int j = 1; j < cur; j++) if(p <= c[j].ot) t[i].tot++, t[i].cv.push_back(j), c[j].ct++;
		}
		for(int i = 1; i <= n; i++) cnt += (!c[i].ct); n -= cnt, cnt = 0; sort(t + 1, t + m + 1, cmp2);
		for(int i = 1; i <= m; i++)
		{
			flg = 1; for(int j = 0; j < t[i].tot; j++) if(c[t[i].cv[j]].ct <= 1) {flg = 0; break; }
			if(flg) for(int j = 0; j < t[i].tot; j++) c[t[i].cv[j]].ct--; cnt += flg;
		}
		cout << n << " " << cnt << endl;
	}
	
	return 0;
}