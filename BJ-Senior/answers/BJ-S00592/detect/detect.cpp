#include <bits/stdc++.h>

inline void file () {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
}

constexpr int N = 1e5 + 5;
constexpr int M = 1e5 + 5;

int n, m, L, V;
int d[N], v[N], a[N];
int p[M];

inline bool detected (int i, int j) {
	// i <= n, j <= m
	// assert(p[j] >= d[i]);
	if (p[j] < d[i])
		return 0;
	return v[i] * v[i] + 2LL * a[i] * (p[j] - d[i]) > V * V;
}

void solve () {
	std::cin >> n >> m >> L >> V;
	for (int i = 1; i <= n; ++ i)
		std::cin >> d[i] >> v[i] >> a[i];
	for (int i = 1; i <= m; ++ i)
		std::cin >> p[i];
	
//	std::sort(p + 1, p + m + 1);
//	m = std::unique(p + 1, p + m + 1) - p - 1;
	
	int ans1 = 0, ans2 = 0;
	std::vector <std::array <int, 2>> rng;
	
	for (int i = 1; i <= n; ++ i) {
		if (a[i] >= 0) {
			if (p[m] >= d[i]) {
				if (detected(i, m)) {
					ans1 ++ ;
//					std::cerr << "i = " << i << "\n";
					int l = 1, r = m;
					while (l < r) {
						int mid = l + r >> 1;
						if (detected(i, mid)) r = mid;
						else l = mid + 1;
					}
					rng.push_back({r, m});
				}
			}
		} else {
			int t = std::lower_bound(p + 1, p + m + 1, d[i]) - p;
			if (t != m + 1) {
				if (detected(i, t)) {
					ans1 ++ ;
//					std::cerr << "i = " << i << "\n";
					int l = t, r = m;
					while (l < r) {
						int mid = l + r + 1 >> 1;
						if (detected(i, mid)) l = mid;
						else r = mid - 1;
					}
					rng.push_back({t, r});
				}
			}
		}
	}
	
	std::sort(rng.begin(), rng.end(), [&](const std::array <int, 2> &lhs, const std::array <int, 2> &rhs) {
		return lhs[1] < rhs[1];
	});
	int lst = -1;
	for (auto [l, r] : rng) {
//		std::cerr << "l, r = " << l << " " << r << "\n";
		if (lst < l) {
			ans2 ++ ;
			lst = r;
		}
	}
	
	std::cout << ans1 << " " << m - ans2 << "\n";
}

int main () {
	
	file();
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	
	int t;
	std::cin >> t;
	while (t -- )
		solve();
	
	return 0;
}