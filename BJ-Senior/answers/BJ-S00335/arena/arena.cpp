#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = (1 << 17);

int n, m, K = 0;
int a[N], c[N];
vector<int> d[18];
int T, X[4];

int op[N][18];

vector<int> id[18];
void dfs1(int l, int r, int o, int k = 0) {
	if (l == r) { id[o][k] = l; return;}
	int mid = (l + r) >> 1, lc = (k << 1), rc = (lc | 1);
	if (r > n) {
		dfs1(l, mid, o - 1, lc);
		if (mid + 1 <= n) dfs1(mid + 1, r, o - 1, rc);
	} else {
		dfs1(l, mid, o - 1, lc);
		dfs1(mid + 1, r, o - 1, rc);
		if (!d[o][k]) id[o][k] = (a[id[o - 1][lc]] >= o ? id[o - 1][lc] : id[o - 1][rc]);
		else id[o][k] = (a[id[o - 1][rc]] >= o ? id[o - 1][rc] : id[o - 1][lc]);
	}
}

int cnt = 0, S[20], lim[20], vis[N];
ll sum[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= m; ++i) cin >> c[i];
	
	while ((1 << K) < n) K++;
	id[0].resize(1 << K);
	for (int i = 1; i <= K; ++i) {
		d[i].resize(1 << K - i), id[i].resize(1 << K - i);
		string s; cin >> s;
		for (int j = 0; j < d[i].size(); ++j) d[i][j] = s[j] - '0';
	}
	
	for (int i = 1; i <= m; ++i) {
		int k = __builtin_ctz(c[i]);
		if (c[i] == (1 << k)) continue;
		int u = (c[i] >> k) - 1;
		while ((1 << k) < c[i]) op[i][k] = d[k + 1][u >> 1], u >>= 1, ++k;	
	}
	
	cin >> T;
	while (T--) {
		for (int o = 0; o < 4; ++o) cin >> X[o];
		for (int i = 1; i <= n; ++i) a[i] ^= X[i & 3], vis[i] = 0;
		
		dfs1(1, (1 << K), K, 0);
		
		ll ans = 0; int cnt = 0;
		for (int i = 1; i <= m; ++i) {
			if (vis[c[i]]) {
				ans ^= (1ll * i * sum[c[i]]);
				continue;
			}
			vis[c[i]] = 1;
		
			int k = __builtin_ctz(c[i]);
			if (c[i] == (1 << k)) {
				ans ^= (1ll * i * (sum[c[i]] = id[k][0]));
				continue;
			}
			memset(lim, 0, sizeof lim);
			
			int u = (c[i] >> k) - 1, l, r, x = id[k][u]; 
			
			int _k = k, _u = u;
			while ((1 << k) < c[i]) {
				int p = (u >> 1);
				if ((u & 1) && !op[i][k] && a[id[k][u - 1]] >= k + 1) _k = k, _u = u, x = id[k][u - 1];
				u = p, ++k;
			}
			k = _k, u = _u;
			
			cnt = 0;
			while ((1 << k) < c[i]) {
				int p = (u >> 1);
				if (u & 1) {
					if (op[i][k]) {
						if (x == -1) {
							lim[cnt] = k + 1;
							S[cnt++] = id[k][u - 1];
						} else x = (a[x] >= k + 1 ? x : id[k][u - 1]);
					}
				} else {
					if (x == -1) {
						r = (u + 2 << k);
						if (!op[i][k]) lim[cnt] = k + 1;
					} else if (op[i][k]) l = (u + 1 << k) + 1, r = (u + 2 << k), S[cnt++] = x, x = -1;
					else if (a[x] < k + 1) l = (u + 1 << k) + 1, r = (u + 2 << k), x = -1;
				}
				u = p, ++k;
			}
			
			if (x == -1) {
				ll s = 1ll * (l + r) * (r - l + 1) / 2;
				for (int i = cnt - 1; ~i; --i) lim[i] = max(lim[i], lim[i + 1]);
				for (int i = 0; i < cnt; ++i) if (a[S[i]] >= lim[i + 1]) s += S[i];
				ans ^= (i * (sum[c[i]] = s));
			} else ans ^= (1ll * i * (sum[c[i]] = x));
		}
		cout << ans << endl;
		
		for (int i = 1; i <= n; ++i) a[i] ^= X[i & 3];
	}
	
	return 0;
}