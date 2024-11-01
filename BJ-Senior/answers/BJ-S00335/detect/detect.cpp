#include <bits/stdc++.h>
using namespace std;
using DB = long double;

const int N = 1e5 + 10;
const DB eps = 1e-6, inf = 1e9;

int T;
int n, m, L, V;
int d[N], v[N], a[N], p[N];

struct Node {
	int l, r;
	Node(int _l = 0.0, int _r = 0.0) { l = _l, r = _r;}
} s[N];

DB dis(int v_s, int v_t, DB t) { return 1.0 * (v_s + v_t) * t / 2;}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	cin >> T;
	while (T--) {
		cin >> n >> m >> L >> V;
		for (int i = 1; i <= n; ++i) cin >> d[i] >> v[i] >> a[i];
		for (int i = 1; i <= m; ++i) cin >> p[i];
		
		int ans1 = 0, cnt = 0;
		for (int i = 1; i <= n; ++i) {
			DB l, r;
			if (a[i] > 0) {
				l = (v[i] > V ? d[i] : d[i] + dis(v[i], V, 1.0 * (V - v[i]) / a[i]) + eps), r = L;
			}
			else if (a[i] == 0) {
				l = (v[i] > V ? d[i] : inf), r = L;
			}
			else {
				l = (v[i] <= V ? inf : d[i]);
				r = (v[i] <= V ? 0 : min((DB)L, d[i] + dis(v[i], V, 1.0 * (V - v[i]) / a[i]) - eps));
			}
			if (l <= r) {
				int L = lower_bound(p + 1, p + m + 1, l) - p;
				int R = upper_bound(p + 1, p + m + 1, r) - p - 1;
				if (L <= R) ++ans1, s[++cnt] = Node(L, R);
			}
		}
		
		int ans2 = 0;
		sort(s + 1, s + cnt + 1, [&](Node x, Node y) { return x.r < y.r;});
		for (int i = 1, j = 0; i <= cnt; ++i) {
			if (s[i].l > j) j = s[i].r, ++ans2;
		}
		cout << ans1 << ' ' << m - ans2 << endl;
	}
	
	return 0;
}