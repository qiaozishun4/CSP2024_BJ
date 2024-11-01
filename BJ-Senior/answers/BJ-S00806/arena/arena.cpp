# include <bits/stdc++.h>
using namespace std;
	# define int long long
const int MAXN = 2e5 + 10;
int n, m, r[MAXN], c[MAXN], T, d[25][MAXN], a[MAXN];
	int K = 0;
int read() {
	int x = 0; bool f = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = 1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + ch - 48;
		ch = getchar();
	}
	return (f ? -1 : 1) * x;
}
struct node {
	int l, r;
	vector <int> vec;
	node () {
		l = r = -1;
	}
};
int vid[25][MAXN];
node merge(node A, int l, int r) {
	if (l == -1) return A;
	if (A.l == -1) {
		A.l = l, A.r = r;
		return A;
	}
	A.l = min(A.l, l), A.r = max(A.r, r);
	return A;
}
node merge12(node A, node B, int k) {
	if (a[A.vec[0]] >= k) return A;
	else return B;
}
node merge20(node A, node B, int k) {
	node ret;
	for (int i : A.vec) {
		if (a[i] >= k) ret.vec.push_back(i);
		else ret = merge(ret, B.l, B.r);
	}
	ret = merge(ret, A.l, A.r);
	if (A.l != -1) ret = merge(ret, B.l, B.r);
	return ret;
}
node merge21(node A, node B, int k) {
	node ret; bool flag = 0;
	for (int i : A.vec) {
		if (a[i] >= k) ret.vec.push_back(i);
		else flag = 1;
	}
	ret = merge(ret, A.l, A.r);
	if (A.l != -1) flag = 1;
	if (flag) ret.vec.push_back(B.vec[0]);
	return ret;
}
node merge02(node A, node B, int k) {
	node ret = B;
	ret = merge(ret, A.l, A.r);
	return ret;
}
node work(int l, int r, int p) {
//	cerr << l << " " << r << " " << p << endl ;
	node res;
	if (p < l) {
		res.l = l, res.r = r;
		return res;
	}
	if (p >= r) {
		int k = log2(r - l + 1);
		res.vec.push_back(vid[k][r / (r - l + 1)]);
//		cerr << l << " " << r << " " << res.vec[0] << endl ;
		return res;
	}
	int k = log2(r - l + 1), id = r / (r - l + 1), mid = (l + r) >> 1;
	node lch = work(l, mid, p), rch = work(mid + 1, r, p);
	if (d[k][id] == 0) {
		if (p >= mid) res = merge12(lch, rch, k);
		else res = merge20(lch, rch, k);
	} else {
		if (p >= mid) res = merge21(rch, lch, k);
		else res = merge02(rch, lch, k);
	}
//	cerr << l << " " << r << ": " << endl ;
//	cerr << "[" << res.l <<", " << res.r<< "]\n";
//	for (int i : res.vec) cerr << i << " " ;
//	cerr << endl ;
	return res;
}
void solve() {
	for (int i = 1; i <= n; i++) vid[0][i] = i;
	for (int i = 1, t = (1 << K - 1); i <= K; i++, t >>= 1) {
		for (int j = 1; j <= t; j++) {
			if (!d[i][j]) {
				if (a[vid[i - 1][j * 2 - 1]] >= i) vid[i][j] = vid[i - 1][j * 2 - 1];
				else vid[i][j] = vid[i - 1][j * 2];
			} else {
				if (a[vid[i - 1][j * 2]] >= i) vid[i][j] = vid[i - 1][j * 2];
				else vid[i][j] = vid[i - 1][j * 2 - 1];
			}
		}
	}
	int res = 0;
//	for (int i = 1; i <= n; i++) cerr << a[i] << " " ;
//	cerr << endl ;
	for (int i = 1; i <= m; i++) {
		int t = 1, ans = 0;
		while (t < c[i]) t <<= 1;
		node tmp = work(1, t, c[i]);
		if (tmp.l != -1) ans += (tmp.l + tmp.r) * (tmp.r - tmp.l + 1) / 2;
		for (int j : tmp.vec) ans += j;
//		cerr << ans << endl ;
		res ^= (i * ans);
	}
	cout << res << endl ;
}
signed main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		r[i] = read();
	}
	for (int i = 1; i <= m; i++) {
		c[i] = read();
	}
	while ((1 << K) < n) K++;
//	cerr << K << endl ;
	for (int i = 1, t = (1 << K - 1); i <= K; i++, t >>= 1) {
		string s;
		cin >> s;
		for (int j = 1; j <= t; j++) d[i][j] = s[j - 1] - '0';
	}
	T = read();
	while (T--) {
		int x[4];
		for (int i = 0; i < 4; i++) x[i] = read();
	//	cerr << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << endl ;
		for (int i = 1; i <= n; i++) a[i] = r[i] ^ x[i % 4];
		solve();
	}
	return 0;
}