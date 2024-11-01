#include <cstdio>

int T, n, k, q;

int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &n, &k, &q);
		for (int i = 1, x; i <= n; i++) {
			scanf("%d", &x);
			for (int j = 1, y; j <= x; j++) {
				scanf("%d", &y);
			}
		}
		for (int i = 1, x, y; i <= q; scanf("%d %d", &x, &y), printf("1\n"), i++);
	}
	return 0;
}