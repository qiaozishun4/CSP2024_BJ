#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 3005, maxl = 1e6 + 5;
int d[maxn], v[maxn], a[maxn], p[maxn], f[maxn][maxn], mark[maxn], sum[maxl], n, m, L, V;
struct carlim {
	int l, r;
} cpre[maxn], c[maxn];
bool cmp(carlim c1, carlim c2) {
	if (c1.l == c2.l) {
		return c1.r < c2.r;
	}
	return c1.l < c2.l;
}
void clear() {
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			f[i][j] = 1e9;
		}
		mark[i] = false;
	}
	for (int i = 0; i <= L; ++i) {
		sum[i] = 0;
	}
}
signed main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T; cin >> T;
	while (T--) {
		cin >> n >> m >> L >> V;
		clear();
		for (int i = 1; i <= n; ++i) {
			cin >> d[i] >> v[i] >> a[i];
		}
		for (int i = 1; i <= m; ++i) {
			cin >> p[i];
			sum[p[i]]++;
		}
		for (int i = 1; i <= L; ++i) sum[i] += sum[i - 1];
		sort(p + 1, p + 1 + m);
		int ans1 = 0, totcpre = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] == 0) { //匀速行驶
				if (v[i] <= V) continue; //若驶入时不超速,则永远不超速
				else {
					int l = d[i], r = L; //若驶入时超速,则在d[i]到L被判定
					if (sum[r] == sum[l - 1]) { //若此范围内无检查点,则不会被判定为超速
						continue;
					}
					++ans1; //否则记入
					cpre[++totcpre].l = l;
					cpre[totcpre].r = r;
				}
			} else if (a[i] > 0) { //匀加速
				if (v[i] > V) {
					int l = d[i], r = L; //若驶入时超速则在d[i]到L被判定
					if (sum[r] == sum[l - 1]) {
						continue; //若此区间没有检查点
					}
					++ans1;
					cpre[++totcpre].l = l; //否则记入
					cpre[totcpre].r = r;
				} else {
					int l = min(L, (int)(d[i] + 1 + floor((V * V - v[i] * v[i]) * 0.5 / a[i]))), r = L;
					if (sum[r] == sum[l - 1]) {
						continue;
					}
					++ans1;
					cpre[++totcpre].l = l;
					cpre[totcpre].r = r;
				}
			} else {
				if (v[i] <= V) {
					continue;
				} else {
					int l = d[i], r = min(L, (int)(d[i] + ceil((v[i] * v[i] - V * V) * 0.5 / (-a[i])) - 1));
					if (r < l) continue;
					if (sum[r] == sum[l - 1]) {
						continue;
					}
					++ans1;
					cpre[++totcpre].l = l;
					cpre[totcpre].r = r;
				}
			}
		} //calc the speeding cars' first/last detected position
		for (int i = 1; i <= totcpre; ++i) {
			if (mark[i]) continue;
			for (int j = 1; j <= totcpre; ++j) {
				if (i == j) continue;
				if (cpre[i].l <= cpre[j].l && cpre[i].r >= cpre[j].r) {
					mark[i] = true;
					break;
				}
			}
		} //delete the supersets
		int totc = 0;
		for (int i = 1; i <= totcpre; ++i) {
			if (mark[i]) continue;
			c[++totc] = cpre[i];
		}
		sort(c + 1, c + 1 + totc, cmp);
		int pl = 1, pr = 1, mi = 0;
		f[0][0] = 0;
		for (int i = 1; i <= totc; ++i) {
			while (pl <= m && p[pl] < c[i].l) ++pl;
			pr = pl;
			while (pr <= m && p[pr] <= c[i].r) ++pr;
			--pr;
			mi = 1e9;
			for (int j = 0; j < pl; ++j) {
				mi = min(mi, f[i - 1][j]);
			}
			for (int j = pl; j <= pr; ++j) {
				f[i][j] = min(f[i][j], f[i - 1][j]);
				f[i][j] = min(f[i][j], mi + 1);
			}
		} //DP
		int ans = 1e9;
		for (int j = pl; j <= pr; ++j) {
			ans = min(ans, f[totc][j]);
		}
		if (ans1 == 0) {
			cout << ans1 << ' ' << m << endl;
			continue;
		}
		cout << ans1 << ' ' << m - ans << endl;
	}
	return 0;
}