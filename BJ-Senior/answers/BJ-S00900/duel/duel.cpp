#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], mx, t[N];
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], t[a[i]]++;
	for (int i = 1; i <= 100000; i++) mx = max(mx, t[i]);
	cout << mx << '\n';
	return 0;
}