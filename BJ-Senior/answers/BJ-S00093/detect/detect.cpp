#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int T, n, m, L, V, d[MAXN + 5], v[MAXN + 5], a[MAXN + 5], p[MAXN + 5], tmp, ans1, ans2, x, y;
vector<int> s[MAXN + 5], t[MAXN + 5];
set<int> st;
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &T);
	while (T --) {
		scanf("%d%d%d%d", &n, &m, &L, &V);
		for (int i = 1; i <= n; i ++)
			scanf("%d%d%d", d + i, v + i, a + i);
		for (int i = 1; i <= m; i ++) {
			scanf("%d", p + i);
			s[i].clear();
			t[i].clear();
		}
		ans1 = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[i] == 0) {
				if (v[i] > V) {
					x = lower_bound(p + 1, p + m + 1, d[i]) - p;
					if (x <= m) {
						ans1 ++;
						s[x].push_back(i);
						t[m].push_back(i);
					}
				}
			} else {
				if (a[i] > 0) {
					tmp = d[i] + (V * V - v[i] * v[i]) / (2 * a[i]);
					x = v[i] > V ? lower_bound(p + 1, p + m + 1, d[i]) - p : upper_bound(p + 1, p + m + 1, tmp) - p;
					if (x <= m) {
						ans1 ++;
						s[x].push_back(i);
						t[m].push_back(i);
					}
				} else if (v[i] > V) {
					tmp = d[i] + (V * V - v[i] * v[i] + 2 * a[i]) / (2 * a[i]);
					x = lower_bound(p + 1, p + m + 1, d[i]) - p;
					y = lower_bound(p + 1, p + m + 1, tmp) - p - 1;
					if (x <= y) {
						ans1 ++;
						s[x].push_back(i);
						t[y].push_back(i);
					}
				}
			}
		}
		st.clear();
		ans2 = 0;
		for (int i = 1; i <= m; i ++) {
			for (int j = 0; j < s[i].size(); j ++)
				st.insert(s[i][j]);
			for (int j = 0; j < t[i].size(); j ++)
				if (st.count(t[i][j])) {
					st.clear();
					ans2 ++;
					break;
				}
		}
		printf("%d %d\n", ans1, m - ans2);
	}
	return 0;
}
