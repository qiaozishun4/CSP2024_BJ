#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 131100;
int n, m, k, a1[N], a[N], c[N];
int id[N], tp[N << 1], up[N << 1], dep[N << 1];
ll sum[N << 1];
char s[N];
void build(int p, int L, int R) {
	sum[p] = (L + R) * (R - L + 1) / 2;
	dep[p] = dep[p >> 1] - 1;
	if (L == R) {
		up[p] = L;
		id[L] = p;
		return ;
	}
	int mid = (L + R) >> 1;
	build(p << 1, L, mid);
	build(p << 1 | 1, mid + 1, R);
	if (R <= n)
		up[p] = (tp[p] ? (a[up[p << 1 | 1]] >= dep[p] ? up[p << 1 | 1] : up[p << 1]) : (a[up[p << 1]] >= dep[p] ? up[p << 1] : up[p << 1 | 1]));
	//cerr << p << ' ' << L << ' ' << R << ',' << tp[p] << ':' << sum[p] << ',' << up[p] << ',' << dep[p] << '\n';
}
ll qry(int pos) {
	if (pos == (1 << k))
		return up[1];
	int p = id[pos + 1], minx = 0, d = 1;
	ll res = pos;
	while (p > 1) {
		int f = (p >> 1);
		if (p & 1) {
			if (tp[f]) {
				if (minx < d)
					minx = min(minx, a[up[p ^ 1]]), res += up[p ^ 1] * (a[up[p ^ 1]] >= k);
			} else {
				//cerr << up[p ^ 1] << ' ' << a[up[p ^ 1]] << '\n';
				if (a[up[p ^ 1]] >= d)
					minx = a[up[p ^ 1]], res = up[p ^ 1] * (a[up[p ^ 1]] >= k);
			}
		} else {
			if (tp[f]) {
				minx = min(minx, d);
				res += sum[p ^ 1];
			} else {
				if (minx < d)
					minx = 0, res += sum[p ^ 1];
			}
		}
		//cerr << p << ' ' << f << ',' << tp[f] << ':' << minx << ' ' << res << '\n';
		p = f;
		++d;
	}
	return res;
}
void work() {
	dep[0] = k + 1;
	build(1, 1, 1 << k);
	ll res = 0;
	for (int i = 1; i <= m; i++) {
		res ^= i * qry(c[i]);
	}
	printf("%lld\n", res);
}
int main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a1[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &c[i]);
	}
	while ((1 << k) < n)
		++k;
	int tot = (1 << k);
	for (int i = 1; i <= k; i++) {
		scanf("%s", s + 1);
		for (int j = 1; j <= (1 << (k - i)); j++)
			tp[(1 << (k - i)) + j - 1] = s[j] - '0';
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		int x[4];
		scanf("%d%d%d%d", x, x + 1, x + 2, x + 3);
		for (int i = 1; i <= n; i++) {
			a[i] = a1[i] ^ x[i % 4];
		}
		work();
	}
	return 0;
}
