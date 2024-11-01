#include <bits/stdc++.h>
using namespace std;
int t, n, m, L, V, d[100010], v[100010], a[100010], p[100010];
bool yes[100010];
int beg[100010], eed[100010];
inline int calx(int vt, int vchu, int aa) {
	return (vt * vt - vchu * vchu) / (2 * aa);
}
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		memset(yes, 0, sizeof(yes));
		memset(beg, 0, sizeof(beg));
		memset(eed, 0, sizeof(eed));
		scanf("%d%d%d%d", &n, &m, &L, &V);
		for (int i = 1; i <= n; i++) scanf("%d%d%d", &d[i], &v[i], &a[i]);
		for (int i = 1; i <= m; i++) scanf("%d", &p[i]);
		sort(p + 1, p + m + 1);
		p[m + 1] = 0x3f3f3f3f;
		int maxp = p[m], ans1 = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] > 0) {
				yes[i] = (v[i] * v[i] + 2 * a[i] * (maxp - d[i])) > (V * V) && d[i] <= maxp;
			} else if (a[i] == 0) {
				yes[i] = (v[i] > V) && upper_bound(p + 1, p + m + 1, d[i] - 1) != p + m + 1;
			} else { // a[i] < 0
				// upper_bound = big, no equal; so -1
				yes[i] = (v[i] * v[i] + 2 * a[i] * (p[upper_bound(p + 1, p + m + 1, d[i] - 1) - p] - d[i])) > (V * V) && upper_bound(p + 1, p + m + 1, d[i] - 1) != p + m + 1;
			}
			ans1 += yes[i];
		}
		printf("%d ", ans1);
		for (int i = 1; i <= n; i++) {
			if (!yes[i]) continue;
			if (a[i] > 0) {
				beg[upper_bound(p + 1, p + m + 1, d[i] + max(calx(V, v[i], a[i]), 0)) - p]++;
			} else if (a[i] == 0) {
				beg[upper_bound(p + 1, p + m + 1, d[i] - 1) - p]++;
			} else { // a[i] < 0
				beg[upper_bound(p + 1, p + m + 1, d[i] - 1) - p]++;
				if ((V * V - v[i] * v[i]) % (2 * a[i]) == 0) {
					eed[upper_bound(p + 1, p + m + 1, d[i] + calx(V, v[i], a[i]) - 1) - p]++;
				} else {
					eed[upper_bound(p + 1, p + m + 1, d[i] + calx(V, v[i], a[i])) - p]++;
				}
			} 
		}
		int ans2 = 0, cnt = 0;
		bool flag = 1;
		for (int i = 1; i <= m; i++) {
		// cout << beg[i] << " " << eed[i] << endl;
			if (beg[i] == 0 && eed[i] == 0) continue;
			if (beg[i] == 0 && eed[i] != 0) {
				flag = 1;
			}
			if (beg[i] != 0 && eed[i] == 0) {
				if (flag) {
					ans2++;
					flag = 0;
				} else {
					continue;
				}
			}
			if (beg[i] != 0 && eed[i] != 0) {
				ans2++;
			}
		}
		printf("%d\n", m - ans2);
	}
	return 0;
}
