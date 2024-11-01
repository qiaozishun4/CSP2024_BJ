# include <bits/stdc++.h>
using namespace std;
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
const double eps = 1e-9;
const int MAXN = 1e5 + 10;
int T, n, m;
double L;
double p[MAXN];
double V, d[MAXN], v[MAXN], a[MAXN];
double calc(double v0, double v1, double a) {
	return (v1 * v1 - v0 * v0) / (2 * a);
}
struct node {
	int l, r;
}s[MAXN], s2[MAXN];
bool cmp(node A, node B) {
	return (A.l < B.l) || (A.l == B.l && A.r > B.r);
}
int tot = 0, tot2 = 0;

int bit[MAXN];
int lowbit(int x) { return x & (-x); }
void change(int x, int y) {
	for (; x <= m; x += lowbit(x)) bit[x] += y;
}
int query(int x) {
	int ans = 0;
	for (; x; x -= lowbit(x)) ans += bit[x];
	return ans;
}
void solve() {
	tot = tot2 = 0;
	memset(bit, 0, sizeof bit);
	n = read(), m = read(), L = read(), V = read();
	for (int i = 1; i <= n; i++) {
		d[i] = read(), v[i] = read(), a[i] = read();
	}
	for (int i = 1; i <= m; i++) p[i] = read();
	int ans1 = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < 0) {
			double t = calc(v[i], V, a[i]);
			if (t > 0) {
				int l = lower_bound(p + 1, p + m + 1, d[i]) - p;
				int r = lower_bound(p + 1, p + m + 1, d[i] + t) - p - 1;
				if (l <= r) {
					s[++tot] = {l, r};
					ans1++;
				}
			}
		} else if (fabs(a[i]) < eps) {
			if (v[i] > V) {
				int l = lower_bound(p + 1, p + m + 1, d[i]) - p;
				int r = m;
				if (l <= r) {
					s[++tot] = {l, r};
					ans1++;
				}
			}
		} else {
			double t = calc(v[i], V, a[i]);
			if (t < 0) {
				int l = lower_bound(p + 1, p + m + 1, d[i]) - p;
				int r = m;
				if (l <= r) {
					s[++tot] = {l, r};
					ans1++;
				}
			} else if (d[i] + t - L < eps) {
				int l = upper_bound(p + 1, p + m + 1, d[i] + t) - p;
				int r = m;
				if (l <= r) {
					s[++tot] = {l, r};
					ans1++;
				}
			}
		}
	}
	sort(s + 1, s + tot + 1, cmp);
	for (int i = tot; i >= 1; i--) {
		//	cout << s[i].l << " " << s[i].r << endl ;
		if (query(s[i].r) == 0) {
			s2[++tot2] = s[i];
		//	cout << "! " << s[i].l << " " << s[i].r << endl ;
		}
		change(s[i].r, 1);
	}
	sort(s2 + 1, s2 + tot2 + 1, cmp);
	memset(bit, 0, sizeof bit);
	int ans2 = m;
	for (int i = 1; i <= tot2; i++) {
		//cout << i << endl ;
		if ((query(s2[i].r) - query(s2[i].l - 1)) > 0) continue; 
		ans2--;
		change(s2[i].r, 1);
	}
	cout << ans1 << " " << ans2 << endl ;
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
	T = read();
	while (T--) {
		solve();
	}
	return 0;
}