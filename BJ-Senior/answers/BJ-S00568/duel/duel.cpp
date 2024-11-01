#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
int a[N];

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int p = 1, q;
	int ans = n;
	while (q <= n) {
		int t = upper_bound(a + 1, a + n + 1, a[p]) - a;
		q = max(t, q);
		int tmp = a[p];
		while (a[p] == tmp && q <= n) {
			q++; p++;
			ans--;
		}
	}
	printf("%d\n", ans);
	return 0;
}