#include <bits/stdc++.h>

using namespace std;

long long t, n, dp[1001] = {-1, -1};
long long a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	scanf("%lld", &t);
	for (int i = 2; i <= 1000; i++) {
		long long mn = LLONG_MAX;
		for (int j = 0; j < 10; j++) {
			if (dp[a[j]] != -1 && i >= a[j] && !(i != a[j] && dp[i - a[j]] == -1) && !(i == a[j] && j == 0))
				if (!(i == a[j] && a[j] == 0)) {
					if (i == a[j]) {
						if (j >= 0)
							mn = min(mn, j * 1ll);
					}
					else {
						if (dp[i - a[j]] >= 0)
							mn = min(mn, (dp[i - a[j]]) * 10ll + j);
					}
				}
		}
		if (mn == LLONG_MAX)
			dp[i] = -1;
		else
			dp[i] = mn;
	}
	while (t--) {
		scanf("%lld", &n);
		printf("%lld\n", dp[n]);
	}
	return 0;
}
