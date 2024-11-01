#include <bits/stdc++.h>

inline void file () {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
}

using i64 = long long;

constexpr i64 inf64 = 0x3f3f3f3f3f3f3f3f;

constexpr int N = 2e5 + 5;
constexpr int M = 1e6 + 5;

int n, A[N];
i64 P[N], S[N], F[N], G[M];

void solve () {
	for (int i = 0; i <= 1000000; ++ i)
		G[i] = -inf64;
	
	std::cin >> n;
	for (int i = 1; i <= n; ++ i)
		std::cin >> A[i];
	
	P[1] = 0LL;
	for (int i = 2; i <= n; ++ i)
		P[i] = P[i - 1] + (A[i - 1] == A[i] ? A[i] : 0);
	S[n] = 0LL;
	for (int i = n - 1; i >= 1; -- i)
		S[i] = S[i + 1] + (A[i + 1] == A[i] ? A[i] : 0);
	
	int p1 = 1, p2 = 2;
	for (int i = 1; i <= n; ++ i) {
		F[i] = P[i];
		if (p1 == A[i + 1]) F[i] = std::max(F[i], G[p2] + P[i]);
		else F[i] = std::max(F[i], G[p1] + P[i]);
		F[i] = std::max(F[i], G[A[i + 1]] + P[i] + A[i + 1]);
		
		const i64 t = F[i] - P[i] - (A[i] == A[i + 1]) * A[i];
		if (t > G[A[i]]) {
			G[A[i]] = t;
			if (p2 == A[i]) {
				if (G[p1] < G[p2])
					std::swap(p1, p2);
			} else if (p1 != A[i]) {
				if (G[A[i]] > G[p1]) {
					p2 = p1;
					p1 = A[i];
				} else if (G[A[i]] > G[p2]) {
					p2 = A[i];
				}
			}
		}
	}
	
	i64 ans = P[n];
	for (int i = 1; i < n; ++ i) {
		ans = std::max(ans, F[i] + S[i + 1]);
	}
	std::cout << ans << "\n";
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