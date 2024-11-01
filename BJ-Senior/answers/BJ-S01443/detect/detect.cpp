#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 100005;
struct node {
	int l, r;
} a[N];
int p[N];
inline int up(int x, int y) {
	return x / y + !!(x % y);
}
inline int pw(int x) {
	return x * x;
}
bool cmp(node &a, node &b) {
	return a.r < b.r;
}
int q[N], dp[N];
void work() {
	int n, m, L, V;
	scanf("%d%d%d%d", &n, &m, &L, &V);
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		int d, v, ad;
		scanf("%d%d%d", &d, &v, &ad);
		if (ad < 0) {
			if (v < V)
				continue;
			a[++tot].l = d;
			a[tot].r = min(L, d + up(pw(v) - pw(V), -2 * ad) - 1);
			if (a[tot].r < a[tot].l)
				--tot;
			//cerr << a[tot].l << ' ' << a[tot].r << '\n';
		} else if (ad == 0) {
			if (v > V) {
				a[++tot].l = d;
				a[tot].r = L;
			}
		} else {
			if (v <= V) {
				a[++tot].l = (pw(V) - pw(v)) / (2 * ad) + 1 + d;
			} else
				a[++tot].l = d;
			a[tot].r = L;
			if (a[tot].r < a[tot].l)
				--tot;
		}
	}
	sort(a + 1, a + tot + 1, cmp);
	int l = 1, r = 1;
	q[1] = 0;
	p[0] = -1;
	int now = 1, lim = -1, res1 = 0;
	for (int i = 1; i <= m + 1; i++) {
		if (i <= m)
			scanf("%d", &p[i]);
		else
			p[i] = L + 1;
		while (now <= tot && a[now].r < p[i]) {
			if (a[now].l <= p[i - 1])
				lim = max(lim, a[now].l), ++res1;
			++now;
		}
		while (l <= r && p[q[l]] < lim)
			++l;
		assert(l <= r);
		dp[i] = dp[q[l]] + 1;
		while (l <= r && dp[i] <= dp[q[r]])
			--r;
		q[++r] = i;
	}
	printf("%d %d\n", res1, m + 1 - dp[m + 1]);
}
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		work();
	}
	return 0;
}

