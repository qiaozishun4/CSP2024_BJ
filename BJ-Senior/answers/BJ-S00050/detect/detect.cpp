#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define int long long

const int MAXN = 3005;

int T;
long long n, m, L, V;
//  Ent      Ini      Inc
int d[MAXN], v[MAXN], a[MAXN];
//  Det
int p[MAXN];
// [)
pair<int, int> secs[MAXN];
vector<int> dets[MAXN];
vector<int> detd[MAXN];
int ndet;

bool useA;
bool useB;

int bomb_ans = 100000000;
bool sel[MAXN];
set<int> bomb;

void dfs(int k) {
	if (k == m + 1) {
		bomb.clear();
		int cnt = 0;
		for (int i = 1; i <= m; i++) {
			if (sel[i]) {
				for (int j : dets[i]) {
					bomb.insert(j);
				}
				cnt++;
			}
		}
		if (bomb.size() == ndet)
			bomb_ans = min(bomb_ans, cnt);
		return;
	}
	sel[k] = 1;
	dfs(k + 1);
	sel[k] = 0;
	dfs(k + 1);
}

signed main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%lld", &T);
	while (T--) {
		// int ndet = 0;
		ndet = 0;
		useA = 1;
		useB = 1;
		scanf("%lld %lld %lld %lld", &n, &m, &L, &V);
		for (int i = 1; i <= n; i++) {
			scanf("%lld %lld %lld", d + i, v + i, a + i);
			// cout << d[i] << " " << v[i] << " " << a[i] << endl;
			if (a[i] > 0) {
				secs[i] = make_pair(d[i] + ((V * V - v[i] * v[i]) / (2 * a[i])) + 1, L + 1);
			} else if (a[i] < 0) {
				if (v[i] > V) {
					if (V * V - v[i] * v[i] % (2 * a[i]))
						secs[i] = make_pair(d[i], d[i] + ((V * V - v[i] * v[i]) / (2 * a[i])) + 1);
					else
						secs[i] = make_pair(d[i], d[i] + ((V * V - v[i] * v[i]) / (2 * a[i])));
				} else {
					secs[i] = make_pair(0, 0);
				}
			} else {
				if (v[i] > V)
					secs[i] = make_pair(d[i], L + 1);
				// puts("1");
			}
			if (a[i] < 0)
				useA = 0;
			if (a[i] >= 0)
				useB = 0;
			// cout << secs[i].first << " " << secs[i].second << endl;
				// puts("2");
		}
		for (int i = 1; i <= m; i++) {
			scanf("%lld", p + i);
		}
		sort(p + 1, p + 1 + m);
		if (useA) {
			for (int i = 1; i <= n; i++) {
				ndet += (p[m] >= secs[i].first && p[m] < secs[i].second);
			}
			cout << ndet << " " << m - (ndet != 0) << endl;
			// printf("%lld %lld\n", ndet, m - (ndet != 0));
		} else if (m <= 30) {
			for (int i = 1; i <= n; i++)
				detd[i].clear();
			for (int i = 1; i <= m; i++)
				dets[i].clear();
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= n; j++) {
					if (p[i] >= secs[j].first && p[i] < secs[j].second) {
						dets[i].push_back(j);
						detd[j].push_back(j);
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				ndet += detd[i].size() != 0;
			}
			bomb_ans = 100000000;
			dfs(1);
			cout << ndet << " " << m - bomb_ans << endl;
		} else {
			for (int i = 1; i <= n; i++)
				detd[i].clear();
			for (int i = 1; i <= m; i++)
				dets[i].clear();
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= n; j++) {
					if (p[i] >= secs[j].first && p[i] < secs[j].second) {
						dets[i].push_back(j);
						detd[j].push_back(j);
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				ndet += detd[i].size() != 0;
			}
			cout << ndet << " " << ndet << endl;
			// printf("%lld %lld\n", ndet, ndet);
		}
	}
	return 0;
}