#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 2e18;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	constexpr int N = 1e6 + 5;
	std::vector<i64> max(N, -inf);
	i64 tmax = 0;

	for (int i = 1; i < n; i++) {
		i64 dp = std::max(tmax, max[a[i]] + a[i]) - (a[i - 1] == a[i] ? a[i] : 0);
		max[a[i - 1]] = std::max(max[a[i - 1]], dp);
		tmax = std::max(tmax, dp);
	}

	i64 ans = tmax;
	for (int i = 1; i < n; i++) {
		ans += a[i - 1] == a[i] ? a[i] : 0;
	}

	std::cout << ans << "\n";
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}