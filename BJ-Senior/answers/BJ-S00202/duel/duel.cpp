#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, ans, a[N];

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2, j = 1; i <= n; i++) {
		if (a[i] > a[j]) {
			ans++;
			j++;
		}
	}
	cout << n - ans << '\n';

	return 0;
}