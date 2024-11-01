#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, m, L, V, l[N], r[N], p[N];
bool yes[N];
struct Car {int d, v, a;} c[N];
struct Pos {int l, r;} det[N];
bool cmp(Pos x, Pos y) {return x.r < y.r;}
int find(int d, int v, int a) {
	int l = 1, r = m, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1, now = (v * v + 2 * a * (p[mid] - d));
		if (p[mid] >= d && now > V * V) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}
int find2(int l0, int d, int v, int a) {
	int l = l0, r = m, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1, now = (v * v + 2 * a * (p[mid] - d));
		if (now > V * V) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m >> L >> V;
		for (int i = 1; i <= n; i++) yes[i] = 0, det[i].l = det[i].r = 0;
		for (int i = 1; i <= n; i++) cin >> c[i].d >> c[i].v >> c[i].a;
		for (int i = 1; i <= m; i++) cin >> p[i];
		for (int i = 1; i <= n; i++) {
			if (c[i].a == 0) {
				if (c[i].v <= V) continue;
				det[i].l = lower_bound(p + 1, p + m + 1, c[i].d) - p;
				if (p[m] >= c[i].d) det[i].r = m, yes[i] = 1;
				else det[i].l = det[i].r = 0;
			} if (c[i].a > 0) {
				det[i].l = find(c[i].d, c[i].v, c[i].a);
				int lst = c[i].v * c[i].v + 2 * c[i].a * (p[m] - c[i].d);
				if (p[m] >= c[i].d && lst > V * V) det[i].r = m, yes[i] = 1;
				else det[i].l = det[i].r = 0;
			} if (c[i].a < 0) {
				int fst = lower_bound(p + 1, p + m + 1, c[i].d) - p;
				int now = c[i].v * c[i].v + 2 * c[i].a * (p[fst] - c[i].d);
				if (now <= V * V) det[i].l = det[i].r = 0;
				else yes[i] = 1, det[i].l = fst, det[i].r = find2(fst, c[i].d, c[i].v, c[i].a);
			}
		}
		int nowr = 0, cnt = 0, ans = 0;
		for (int i = 1; i <= n; i++) ans += yes[i];
		sort(det + 1, det + n + 1, cmp);
		for (int i = 1; i <= n; ) {
			while (i <= n && det[i].l <= nowr) i++;
			if (i <= n) cnt++, nowr = det[i].r;
		}
		cout << ans << ' ' << m - cnt << '\n';
	}
	return 0;
}