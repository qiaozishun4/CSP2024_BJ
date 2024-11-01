#include <bits/stdc++.h>
using namespace std;
int n, a[100010], cnt[100010], maxn = 0, minn = 0x3f3f3f3f;
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
		maxn = max(maxn, a[i]);
		minn = min(minn, a[i]);
	}
	int ans = cnt[minn];
	for (int i = minn + 1; i <= maxn; i++) {
		if (cnt[i] == 0) continue;
		int x = cnt[i] - ans;
		// if x == 0: sha wan le; bu yong bian
		if (x < 0) {
			ans = cnt[i] - x; // cnt[i] + (-x)
		}
		if (x > 0) {
			ans = cnt[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
