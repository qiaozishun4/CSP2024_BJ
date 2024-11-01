#include <bits/stdc++.h>

void solve() {
	int n, m, l, vl;
	std::cin >> n >> m >> l >> vl;

	std::vector<int> d(n), v(n), a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> d[i] >> v[i] >> a[i];
	}

	std::vector<int> p(m);
	for (int i = 0; i < m; i++) {
		std::cin >> p[i];
	}

	std::vector<int> max(m, -1);
	int ans1 = 0;

	for (int i = 0; i < n; i++) {
		int s, t;
		if (a[i] == 0) {
			if (v[i] <= vl) {
				s = -1, t = -1;
			} else {
				s = d[i], t = l;
			}
		} else if (a[i] > 0) {
			if (v[i] <= vl) {
				s = d[i] + (vl * vl - v[i] * v[i]) / (2 * a[i]) + 1, t = l;
			} else {
				s = d[i], t = l;
			}
		} else {
			if (v[i] <= vl) {
				s = -1, t = -1;
			} else {
				s = d[i], t = d[i] + (v[i] * v[i] - vl * vl - 1) / (-2 * a[i]);
			}
		}

		int ss = std::lower_bound(p.begin(), p.end(), s) - p.begin(), tt = std::upper_bound(p.begin(), p.end(), t) - p.begin();
		if (ss < tt) {
			max[tt - 1] = std::max(max[tt - 1], ss);
			ans1++;
		}
	}

	int last = -1, ans2 = 0;
	for (int i = 0; i < m; i++) {
		if (last < max[i]) {
			last = i;
		} else {
			ans2++;
		}
	}

	std::cout << ans1 << " " << ans2 << "\n";
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}