#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
int T, n, a[MAXN + 5], dp[MAXN + 5], pre[MAXN + 5], lst, ans;
inline int calc(int x, int y) {
	return a[x] == a[y] ? a[x] : 0;
}
inline int solve(int x) {
	int lst[2] = {0, 0}, res = 0;
	for (int i = 1; i <= n; i ++) {
		res += calc(lst[x >> (i - 1) & 1], i);
		lst[x >> (i - 1) & 1] = i;
	}
	return res;
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			scanf("%d", a + i);
		if (n <= 15) {
			ans = 0;
			for (int i = 0; i < (1 << n); i ++)
				ans = max(ans, solve(i));
			printf("%d\n", ans);
		} else {
			for (int i = 1; i <= n; i ++) {
				if (a[i] != a[i - 1]) lst = i - 1;
				dp[i] = 0;
				pre[i] = pre[i - 1] + calc(i, i - 1);
				if (lst == i - 1)
					dp[i] = dp[i - 1] + calc(i - 1, i + 1);
				for (int j = 0; j <= lst; j ++) {
					dp[i] = max(dp[i], dp[j] + pre[lst] - pre[j + 1] + calc(j, lst + 1) + pre[i] - pre[lst + 1] + calc(lst, i + 1));
				}
			}
			printf("%d\n", dp[n]);
		}
	}
	return 0;
}
