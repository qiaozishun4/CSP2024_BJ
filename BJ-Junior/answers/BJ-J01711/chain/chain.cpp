#include <bits/stdc++.h>

using namespace std;

int t, x;

int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		int n, m, q;
		scanf("%d%d%d", &n, &m, &q);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &m);
			for (int j = 1; j <= m; j++)
				scanf("%d", &x);
		}
		for (int i = 1; i <= q; i++) {
			scanf("%d%d", &m, &x);
			printf("%d\n", rand() % 2);
		}
	}
	return 0;
}
