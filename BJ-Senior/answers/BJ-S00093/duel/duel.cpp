#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int n, a[MAXN + 5], cnt1, cnt2 = 1, ans;
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i ++) {
		if (a[i] > a[i - 1]) {
			cnt1 += cnt2;
			cnt2 = 0;
		}
		cnt2 ++;
		if (cnt1) {
			cnt1 --;
			ans ++;
		}
	}
	printf("%d\n", n - ans);
	return 0;
}
