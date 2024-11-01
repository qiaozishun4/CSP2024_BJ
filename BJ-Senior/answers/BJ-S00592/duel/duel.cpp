#include <bits/stdc++.h>

inline void file () {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
}

int main () {
	
	file();
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	std::vector <int> a(n);
	for (int i = 0; i < n; ++ i)
		std::cin >> a[i];
	
	std::sort(a.begin(), a.end());
	
	int p = 0;
	for (int i = 1; i < n; ++ i)
		if (a[i] > a[p])
			p ++ ;
	
	std::cout << n - p << "\n";
	
	return 0;
}