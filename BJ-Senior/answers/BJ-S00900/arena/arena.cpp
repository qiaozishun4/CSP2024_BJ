#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, m, a0[N], a[N], c[N], k, X[4], sum, tmpa[N], Ans[N];
bool flgA = 1, vis[10];
string d[N];
int get(int x) {int k = 0; while ((1 << k) < x) k++; return k;}
int get2(int x) {int k = 0; while (x) k++, x >>= 1; return k;}
int work(int g, int l, int r) {
	//cout << g << ' ' << l << ' ' << r << '\n';
	int x = (1 << g), nowd = d[g][(l + x - 1) / x] - '0';
	if (l == r) return l;
	if (l + 1 == r) {
		if (!nowd) {
			if (l == 1) Ans[r] = (tmpa[l] >= g ? l : r);
			return (tmpa[l] >= g ? l : r);
		} else {
			if (l == 1) Ans[r] = (tmpa[r] >= g ? r : l);
			return (tmpa[r] >= g ? r : l);
		}
	}
	int mid = l + (r - l + 1) / 2 - 1;
	int lf = work(g - 1, l, mid), rt = work(g - 1, mid + 1, r);
	if (!nowd) {
		if (l == 1) Ans[r] = (tmpa[lf] >= g ? lf : rt);;
		return (tmpa[lf] >= g ? lf : rt);
	} else {
		if (l == 1) Ans[r] = (tmpa[rt] >= g ? rt : lf);
		return (tmpa[rt] >= g ? rt : lf);
	}
}
void dfs(int step, int lst) {
	if (step > lst) {vis[work(get2(lst) - 1, 1, lst)] = 1; return;}
	for (int i = 0; i <= 3; i++)
		tmpa[step] = i, dfs(step + 1, lst);
}
int main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m, k = get(n);
	for (int i = 1; i <= n; i++) cin >> a0[i];
	for (int i = 1; i <= m; i++) cin >> c[i];
	for (int i = 1; i <= k; i++) cin >> d[i], d[i] = '?' + d[i];
	cin >> T;
	while (T--) {
		cin >> X[0] >> X[1] >> X[2] >> X[3];
		for (int i = 1; i <= n; i++) a[i] = a0[i] ^ X[i % 4];
		int ans = 0;
		if (n <= 8 && m <= 8) {
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= 8; j++) tmpa[j] = a[j], vis[j] = 0;
				dfs(c[i] + 1, (1 << get(c[i]))), sum = 0;
				for (int j = 1; j <= 8; j++) if (vis[j]) sum += j;
				ans ^= (i * sum);
			}
			cout << ans << '\n';
		} else if (flgA) {
			memcpy(tmpa, a, sizeof(tmpa));
			int x = get2(n);
			Ans[1] = 1, work(x, 1, 1 << x);
			for (int i = 1; i <= m; i++) ans ^= (i * Ans[c[i]]);
			cout << ans << '\n';
		}
	}
	return 0;
}