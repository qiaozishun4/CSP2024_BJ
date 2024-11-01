#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int T, n, m, len, mx, ans1, ans2, p[N];
struct node{
	int d, v, a;
}c[N];
int lf[N];
void Max(int &x, int y) {if (x < y) x = y; }

int v2(int v0, int a, int s) {
	return v0 * v0 + 2 * a * s;
}
void work(int d, int v, int a) {
	int nxt = lower_bound(p + 1, p + m + 1, d) - p;
	if (nxt > m) return;
	if (a >= 0) {
		if (v2(v, a, p[m] - d) <= mx) return;
		++ans1;
		int l = nxt, r = m, res = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (v2(v, a, p[mid] - d) > mx) res = mid, r = mid - 1;
			else l = mid + 1;
		}
		Max(lf[m], res);
		//printf("[%d %d]\n", res, m);
	} else {
		if (v2(v, a, p[nxt] - d) <= mx) return;
		++ans1;
		int l = nxt, r = m, res = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (v2(v, a, p[mid] - d) > mx) res = mid, l = mid + 1;
			else r = mid - 1;
		}
		Max(lf[res], nxt);
		//printf("[%d %d]\n", nxt, res);
	}
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m >> len >> mx;
		mx = mx * mx;
		for (int i=1; i<=m; ++i) lf[i] = 0;
		for (int i=1; i<=n; ++i)
			cin >> c[i].d >> c[i].v >> c[i].a;
		for (int i=1; i<=m; ++i) cin >> p[i];
		ans1 = ans2 = 0;
		for (int i=1; i<=n; ++i) 
			work(c[i].d, c[i].v, c[i].a);
		for (int i=1,lst=0; i<=m; ++i)
			if (lst < lf[i]) lst = i, ++ans2;
		cout << ans1 << " " << m - ans2 << "\n";
	}
	return 0;
}