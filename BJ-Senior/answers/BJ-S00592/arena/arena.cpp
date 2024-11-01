#include <bits/stdc++.h>

inline void file () {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
}

using i64 = long long;

constexpr int N = 1e5 + 5;
constexpr int M = 1e5 + 5;

int n, m;
int a[N], c[M];
int d[18][N];

int calc (int turn, int x) {
	if (!turn) {
		return x;
	}
	if (!d[turn][x]) {
		int y = calc(turn - 1, 2 * x);
		if (a[y] >= turn) return y;
		else return calc(turn - 1, 2 * x + 1);
	} else {
		int y = calc(turn - 1, 2 * x + 1);
		if (a[y] >= turn) return y;
		else return calc(turn - 1, 2 * x);
	}
}

namespace Spec {
	int res[20];
	
	void main () {
		for (int i = 0; (1 << i) <= n; ++ i) {
			res[i] = calc(i, 0);
		}
		i64 ans = 0LL;
		for (int i = 1; i <= m; ++ i) {
			for (int j = 0; ; ++ j)
				if ((1 << j) == c[i]) {
					ans ^= (1LL * i * (res[j] + 1));
					break;
				}
		}
		std::cout << ans << "\n";
	}
}

namespace Bf {
	int b[N];
	bool yes[20];
	
	void main () {
		std::memcpy(b, a, sizeof b);
		int ans = 0;
		for (int j = 1; j <= m; ++ j) {
			for (int i = 0; i < c[j]; ++ i)
				a[i] = b[i];
			int k = 0;
			for (; (1 << k) < c[j]; ++ k);
			
			for (int i = 0; i < (1 << k); ++ i)
				yes[i] = 0;
			
			std::function <void(int)> dfs = [&](int i) -> void {
				if (i == (1 << k)) {
					yes[calc(k, 0)] = 1;
					return;
				}
				for (int x = 0; x <= k + 1; ++ x) {
					a[i] = x;
					dfs(i + 1);
				}
			};
			
			dfs(c[j]);
			
			int s = 0;
			for (int i = 0; i < (1 << k); ++ i)
				if (yes[i])
					s += i + 1;
			
			ans ^= (j * s);
		}
		
		std::cout << ans << "\n";
	}
}

int main () {
	
	file();
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	
	bool ok = 1;
	auto chk = [&](int x) -> bool {
		int t = 0;
		for (; (1 << t) < x; ++ t);
		return (1 << t) == x;
	};
	
	std::cin >> n >> m;
	for (int i = 0; i < n; ++ i)
		std::cin >> a[i];
	for (int i = 1; i <= m; ++ i) {
		std::cin >> c[i];
		ok &= chk(c[i]);
	}
	
	int K = 0;
	while ((1 << K) < n) K ++ ;
	
	for (int i = 1; i <= K; ++ i)
		for (int j = 0; j < (1 << K - i); ++ j) {
			char c; std::cin >> c;
			d[i][j] = (c == '1');
		}
	
	int tt; std::cin >> tt;
	int X[4]; std::cin >> X[0] >> X[1] >> X[2] >> X[3];
	for (int i = 0; i < n; ++ i) {
		a[i] ^= X[(i + 1) % 4];
	}
	
	if (ok) Spec::main();
	else Bf::main();
	
	return 0;
}