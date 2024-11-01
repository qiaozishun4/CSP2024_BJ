#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());

	std::queue<int> q;
	for (int i = 0; i < n; i++) {
		if (!q.empty() && q.front() < a[i]) {
			q.pop();
		}
		q.push(a[i]);
	}

	std::cout << q.size() << "\n";
}

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}