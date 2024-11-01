#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
int cnt[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	cin >> n;
	for (int i = 1, x; i <= n; ++i) cin >> x, cnt[x]++;
	
	int ans = 0;
	for (int i = 1; i <= 100000; ++i) ans = max(ans, cnt[i]);
	cout << ans << endl;
	
	return 0;
}