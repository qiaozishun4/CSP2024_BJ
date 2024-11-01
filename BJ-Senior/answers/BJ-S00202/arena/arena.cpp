#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int T, n, m, k, nowr, rmx[18];
long long oans, nans, a_[N], a[N], sum[N], X[4], ans[N];
vector<int> id[N], op[18], mx[18], val[18];
vector<bool> vis[18], vmx[18], hv[18];

int main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 1; i <= 131072; i++) {
		sum[i] = sum[i - 1] + i;
	}
	cin >> n >> m;
	k = 0;
	while ((1 << k) < n) {
		k++;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a_[i];
	}
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		id[x].emplace_back(i);
	}
	for (int i = 1; i <= k; i++) {
		int t = 1 << k - i;
		op[i].resize(t + 1);
		for (int j = 1; j <= t; j++) {
			char c;
			cin >> c;
			op[i][j] = c - '0';
		}
	}
	for (int i = k; i >= 0; i--) {
		int t = 1 << k - i;
		mx[i].resize(t + 1);
		for (int j = 1; j <= t; j++) {
			if (i == k) {
				mx[i][j] = 0;
			} else {
				if (mx[i + 1][j + 1 >> 1] != 0) {
					mx[i][j] = mx[i + 1][j + 1 >> 1];
				} else {
					mx[i][j] = op[i + 1][j + 1 >> 1] != j & 1 ? i + 1 : 0;
				}
			}
		}
	}
	for (int i = 0; i <= k; i++) {
		int t = 1 << k - i;
		vis[i].resize(t + 1);
		val[i].resize(t + 1);
		vmx[i].resize(t + 1);
		hv[i].resize(t + 1);
	}
	cin >> T;
	while (T--) {
		k = 0;
		while (1 << k < n) {
			k++;
		}
		for (int i = 0; i < 4; i++) {
			cin >> X[i];
		}
		for (int i = 1; i <= n; i++) {
			a[i] = min(a_[i] ^ X[i % 4], (long long)k);
		}
		oans = 0;
		nans = 0;
		nowr = k;
		for (int i = 0; i <= k; i++) {
			rmx[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			vis[0][i] = 1;
			val[0][i] = i;
			vmx[0][i] = 0;
			hv[0][i] = 0;
		}
		for (int i = 1; i <= k; i++) {
			int t = 1 << k - i;
			for (int j = 1; j <= t; j++) {
				vmx[i][j] = 0;
				hv[i][j] = 0;
				if (!vis[i - 1][j * 2 - 1]) {
					continue;
				}
				int u = val[i - 1][j * 2 - 1];
				int v = val[i - 1][j * 2];
				if (op[i][j] == 0) {
					if (a[u] >= i) {
						vis[i][j] = 1;
						val[i][j] = u;
					} else {
						vis[i][j] = vis[i - 1][j * 2];
						val[i][j] = v;
					}
				} else {
					if (vis[i - 1][j * 2]) {
						vis[i][j] = 1;
						if (a[v] >= i) {
							val[i][j] = v;
						} else {
							val[i][j] = u;
						}
					} else {
						vis[i][j] = 0;
						val[i][j] = 0;
					}
				}
			}
		}
		for (int i = k; i >= 0; i--) {
			int t = 1 << k - i;
			for (int j = 1; j <= t; j++) {
				if (i < k) {
					hv[i][j] = hv[i + 1][j + 1 >> 1];
				}
				if (vis[i][j] && !hv[i][j]) {
					vmx[i][j] = 1;
					rmx[i] = (1 << i) * j;
					nowr = min(nowr, i);
					nans += a[val[i][j]] >= mx[i][j] ? val[i][j] : 0;
					hv[i][j] = 1;
				}
			}
		}
		for (int i = n; i >= 1; i--) {
			if (k > 0 && 1 << k - 1 >= i) {
				k--;
			}
			while (nowr <= k && !rmx[nowr]) {
				nowr++;
			}
			for (int j : id[i]) {
				ans[j] = nans + sum[1 << k] - sum[rmx[nowr]];
			}
			if (i == 1) {
				break;
			}
			vis[0][i] = 0;
			val[0][i] = 0;
			if (vmx[0][i]) {
				vmx[0][i] = 0;
				rmx[0] = 0;
			}
			int u = i, lst = 0;
			for (int j = 1; j <= k; j++) {
				u = u + 1 >> 1;
				if (!vis[j][u]) {
					break;
				}
				int v = val[j][u];
				if (op[j][u] == 0) {
					if (a[val[j - 1][u * 2 - 1]] >= j) {
						vis[j][u] = 1;
						val[j][u] = val[j - 1][u * 2 - 1];
					} else {
						vis[j][u] = vis[j - 1][u * 2];
						val[j][u] = val[j - 1][u * 2];
					}
				} else {
					if (vis[j - 1][u * 2]) {
						vis[j][u] = 1;
						if (a[val[j - 1][u * 2]] >= j) {
							val[j][u] = val[j - 1][u * 2];
						} else {
							val[j][u] = val[j - 1][u * 2 - 1];
						}
					} else {
						vis[j][u] = 0;
						val[j][u] = 0;
					}
				}
				if (!vis[j][u] && vmx[j][u]) {
					vmx[j][u] = 0;
					rmx[j] = 0;
					lst = j;
					nans -= a[v] >= mx[j][u] ? v : 0;
					break;
				}
				if (vis[j][u]) {
					break;
				}
			}
			u = i;
			for (int j = 1; j <= lst; j++) {
				u = u + 1 >> 1;
				if (vis[j - 1][u * 2 - 1]) {
					vmx[j - 1][u * 2 - 1] = 1;
					rmx[j - 1] = (1 << j - 1) * (u * 2 - 1);
					nowr = min(nowr, j - 1);
					int v = val[j - 1][u * 2 - 1];
					nans += a[v] >= mx[j - 1][u * 2 - 1] ? v : 0;
				}
			}
		}
		for (int i = 1; i <= m; i++) {
			oans ^= ans[i] * i;
		}
		cout << oans << '\n';
	}

	return 0;
}