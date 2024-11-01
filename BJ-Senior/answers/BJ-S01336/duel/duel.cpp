#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, a[N];

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i=1,j=1; i<=n; ++i)
		if (j < i && a[j] < a[i]) ++ans, ++j;
	cout << n - ans << "\n";
	return 0;
}