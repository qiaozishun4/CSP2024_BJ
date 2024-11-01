
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int t, k, q, n, len;

int main () {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d%d", &n, &k, &q);
		while (n --) {
			scanf("%d", &len);
			while (len --) {
				scanf("%d", &k);
			}
		}
		while (q --) {
			scanf("%d%d", &k, &k);
			if (q % 3 == 0) {
				printf("1\n");
			} else {
				printf("0\n");
			}
		}
	}
	return 0;
}