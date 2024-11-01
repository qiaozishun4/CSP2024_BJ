#include <bits/stdc++.h>
#define inf 1e9
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define ll long long
using namespace std;

const int N = 400010, M = 20;
int n, m, q, num, T, a[N], b[N], c[N], X[4];
bool d[N];
int win[N], wner[N], lim[N], id[N];
char s[M][N];
int stac[N], top;

void get_win(int p, int l, int r, int dep, int tot) {
	d[p] = (s[dep][tot] ^ 48);
	if (l == r) {
		id[l] = p, win[p] = b[l], wner[p] = l; return;
	}
	int mid = (l + r) >> 1;
	get_win(ls(p), l, mid, dep - 1, tot * 2 - 1);
	get_win(rs(p), mid + 1, r, dep - 1, tot * 2);
	if (!d[p]) {
		if (win[ls(p)] >= dep) win[p] = win[ls(p)], wner[p] = wner[ls(p)];
		else win[p] = win[rs(p)], wner[p] = wner[rs(p)];
	} else {
		if (win[rs(p)] >= dep) win[p] = win[rs(p)], wner[p] = wner[rs(p)];
		else win[p] = win[ls(p)], wner[p] = wner[ls(p)];
	}
}

void get_lim(int p) {
	lim[p] = 0;
	for (int i=top; i; --i) {
		int dep = i;
		p = stac[i];
		int fa = (p >> 1); int lc = (fa << 1), rc = (fa << 1 | 1);
		if (p == rc) {
			if (!d[fa]) lim[p] = (win[lc] < dep) ? lim[fa] : inf;
			else lim[p] = max(lim[fa], dep);
		} else {
			if (!d[fa]) lim[p] = max(lim[fa], dep);
			else lim[p] = lim[fa];
		}
		//printf("%d ", lim[p]);
	}
	//putchar(10);
}

int main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	scanf("%d%d", &n, &q);
	m = 0, num = 1;
	while (num < n) ++m, num <<= 1;
	for (int i=1; i<=n; ++i) scanf("%d", &a[i]);
	for (int i=1; i<=q; ++i) scanf("%d", &c[i]);
	for (int i=1; i<=m; ++i) scanf("%s", s[i] + 1);
	scanf("%d", &T);
	while (T--) {
		for (int i=0; i<4; ++i) scanf("%d", &X[i]);
		for (int i=1; i<=n; ++i) b[i] = min(500, a[i] ^ X[i % 4]);
		//for (int i=1; i<=n; ++i) printf("%d ", b[i]); putchar(10);
		get_win(1, 1, num, m, 1);
		ll res = 0;
		for (int o=1; o<=q; ++o) {
			int x = c[o];
			int p = id[x], l = x, r = x; top = 0;
			while (l != 1) {
				stac[++top] = p;
				if (p & 1) l -= r - l + 1;
				else r += r - l + 1;
				p >>= 1;
			}
			get_lim(p);
			p = id[x], l = x, r = x;
			int mn = b[x], dep = 1;
			bool nw = false;
			ll ans = (b[x] >= lim[p]) ? x : 0;
			while (l != 1) {
				int fa = (p >> 1); int lc = (fa << 1), rc = (fa << 1 | 1);
				if (p == lc) {
					bool flag = !d[fa] ? mn < dep : 1;
					if (flag && 500 >= lim[fa]) {
						int L = r + 1, R = r + r - l + 1;
						ans += 1ll * (L + R) * (R - L + 1) / 2;
						//printf("addans %d %d, mn = %d, dep = %d\n", L, R, mn, dep);
					}
					if (!d[fa]) {
						if (mn < dep) mn = 0, nw = true;
					} else mn = min(mn, dep), nw = true;
				} else {
					bool flag = !d[fa] ? win[lc] >= dep : mn < dep;
					if (flag && win[lc] >= lim[fa]) ans += wner[lc]/*, printf("addans %d\n", wner[lc])*/;
					if (!d[fa]) {
						if (win[lc] >= dep) mn = win[lc], nw = false;
					} else {
						mn = min(mn < dep ? win[lc] : inf, min(mn >= dep ? mn : inf, nw ? dep : inf));
					}
				}
				if (p == lc) r += r - l + 1;
				else l -= r - l + 1;
				p = fa, ++dep;
			}
			//printf("%lld ", ans);
			res ^= 1ll * o * ans;
		}
		//putchar(10);
		printf("%lld\n", res);
	}
	return 0;
}