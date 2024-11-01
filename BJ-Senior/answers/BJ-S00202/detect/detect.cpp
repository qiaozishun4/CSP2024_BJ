#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int T, n, m, tot, ans, L, V, d[N], v[N], st[N], ed[N], a[N], p[N];

struct A {
	int l, r;

	A (int l = 0, int r = 0):
		l(l), r(r) {}
} t[N];

bool cmp(A x, A y) {
	return x.r < y.r;
}

void work() {
	cin >> n >> m >> L >> V;
	for (int i = 1; i <= n; i++) {
		cin >> d[i] >> v[i] >> a[i];
		st[i] = -1;
		ed[i] = -1;
		if (a[i] > 0) {
			if (V < v[i]) {
				st[i] = d[i];
				ed[i] = L;
			} else {			
				int x = (V * V - v[i] * v[i]) / (2 * a[i]) + 1;
				if (d[i] + x <= L) {
					st[i] = d[i] + x;
					ed[i] = L;
				}
			}
		} else if (a[i] == 0) {
			if (V < v[i]) {
				st[i] = d[i];
				ed[i] = L;
			}
		} else {
			if (V < v[i]) {
				int x = (v[i] * v[i] - V * V + 2 * abs(a[i]) - 1) / (2 * abs(a[i]));
				st[i] = d[i];
				ed[i] = min(d[i] + x - 1, L);
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> p[i];
	}
	tot = 0;
	for (int i = 1; i <= n; i++) {
		if (st[i] == -1) {
			continue;
		}
		int l = lower_bound(p + 1, p + m + 1, st[i]) - p;
		int r = upper_bound(p + 1, p + m + 1, ed[i]) - p - 1;
		if (l > r) {
			continue;
		}
		t[++tot] = A(l, r);
	}
	sort(t + 1, t + tot + 1, cmp);
	ans = 0;
	for (int i = 1, now = 0; i <= tot; i++) {
		if (t[i].l > now) {
			ans++;
			now = t[i].r;
		}
	}
	cout << tot << ' ' << m - ans << '\n';
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		work();
	}

	return 0;
}