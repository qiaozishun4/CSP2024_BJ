#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 200005, M = 1000005;
int a[N];
ll s[N], dp[N];
ll mx[M];
void work() {
	int n;
	scanf("%d", &n);
	ll now = 0;
	memset(mx, -0x3f, sizeof(mx));
	mx[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + (a[i] == a[i - 1]) * a[i];
		dp[i] = max(mx[a[i]] + a[i], now) + s[i - 1];
		now = max(now, dp[i] - s[i]);
		mx[a[i - 1]] = max(mx[a[i - 1]], dp[i] - s[i]);
	}
	printf("%lld\n", now + s[n]);
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		work();
	}
	return 0;
}

