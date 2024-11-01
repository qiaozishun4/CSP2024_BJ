#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int T;
int n, m, L, V;
struct car {
	int d, v, a;
	int l, r;
	bool okl, okr;
	car() {
		okl = true;
		okr = true;
	}
} C[N];

int pos[N];

bool chk(car c, int id) {
	if (id < c.l) return false;
	if (id > c.r) return false;
	if (id == c.l && id == c.r) return c.okl || c.okr;
	if (id == c.l) return c.okl;
	if (id == c.r) return c.okr;
	return true;
}


signed main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%lld", &T);
	while (T--) {
		//duoceqingkong!!!!!!!
		//lld!!!!!!!!!!!!!!!!!!!!!!
		memset(pos, 0, sizeof(pos));
		scanf("%lld%lld%lld%lld", &n, &m, &L, &V);
		for (int i = 1; i <= n; i++) {
			C[i].okl = C[i].okr = true;
		}
		bool flagA = true, flagB = true;
		for (int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &C[i].d, &C[i].v, &C[i].a);
			if (C[i].a != 0) {
				flagA = false;
			}
			if (C[i].a <= 0) {
				flagB = false;
			}
		}
		for (int i = 1; i <= m; i++) scanf("%lld", &pos[i]);
		if (flagA == true) {
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (C[i].v > V && C[i].d <= pos[m]) {
					cnt++;
				}
			}
			if (cnt) printf("%lld %lld\n", cnt, m - 1);
			else printf("0 %lld\n", m);
		} else if (flagB == true) {
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (C[i].d > pos[m]) continue;
				int dx = pos[m] - C[i].d;
				int vtsq = C[i].v * C[i].v + 2 * C[i].a * dx;
				if (vtsq > V * V) {
					cnt++;
				}
			}
			if (cnt) printf("%lld %lld\n", cnt, m - 1);
			else printf("0 %lld\n", m);
		} else {
			int cnt = 0;
			vector<int> f;
			for (int i = 1; i <= n; i++) {
				if (C[i].d > pos[m]) continue;
				int id = lower_bound(pos + 1, pos + m + 1, C[i].d) - pos;
				if (C[i].a == 0) {
					if (C[i].v > V) {
						cnt++;
						f.push_back(i);
						C[i].l = id;
						C[i].r = m;
					}
				} else if (C[i].a > 0) {
					if (C[i].v > V) {
						cnt++;
						f.push_back(i);
						C[i].l = id;
						C[i].r = m;
					} else {
						int A = V * V - C[i].v * C[i].v;
						int B = 2 * C[i].a;
						bool ok = (A % B == 0);
						int tmp = A / B;
						if (!ok) tmp++;
						int idd = lower_bound(pos + 1, pos + m + 1, C[i].d + tmp) - pos;
						C[i].l = tmp + C[i].d;
						C[i].r = m;
						C[i].okl = !((pos[idd] == C[i].d + tmp) && ok);
						///C[i].okl = true;
						if (C[i].l <= C[i].r) {
							if (C[i].l == C[i].r && (!C[i].okl || !C[i].okr)) continue;
							f.push_back(i);
							cnt++;
						}
					}
				} else {
					if (C[i].v <= V) {
						continue;
					}
					int A = V * V - C[i].v * C[i].v;
					int B = 2 * C[i].a;
					bool ok = (A % B == 0);
					A = -A; B = -B;
					int tmp = A / B;
					if (!ok) tmp++;
					int idd = lower_bound(pos + 1, pos + m + 1, C[i].d + tmp) - pos;
					C[i].l = id;
					C[i].r = idd - 1;
					C[i].okr = true;
					if (C[i].l <= C[i].r) {
						if (C[i].l == C[i].r && (!C[i].okl || !C[i].okr)) continue;
						f.push_back(i);
						cnt++;
					}
				}	
			}
			// for (int p : f) {
			// 	cout << C[p].l << " " << C[p].r << " " << C[p].okl << " " << C[p].okr << endl;
			// }
 			printf("%lld ", cnt);
			int ans = 0;
			vector<int> g;
			for (int i = 0; i < (1 << m); i++) {
				int cnt = 0; g.clear();
				for (int j = 1; j <= m; j++) {
					int bit = ((i >> (j - 1)) & 1);
					if (!bit) cnt++;
					else {
						g.push_back(j);
					}
 				}
 				bool flag = true;
 				for (auto p : f) {
 					bool gg = false;
 					for (auto q : g) {
 						gg |= chk(C[p], q);		
 					}
 					//cout << gg << endl;
 					//if (gg == 1) puts("in");
 					flag &= gg;
 				}
 				if (flag) ans = max(ans, cnt);
  			}
  			printf("%lld\n", ans);
		}
	}
	return 0;
}