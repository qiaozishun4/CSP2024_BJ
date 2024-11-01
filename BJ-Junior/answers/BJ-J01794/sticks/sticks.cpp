#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int N = 100010;
int t, n;
int minn[] = {-1, 2, 5, -1, 4, -1, 6, 3, 7, -1};
int minn1[] = {6, 2, 5, -1, -1, -1, -1, -1, 7, -1};
int now[N], len = 0;

int dfs (int n, int k, bool flag) {
	if (n == 0 && k == 0) {
		return 1;
	} if (n <= 1 || k == 0) {
		len --;
		return -1;
	} 
	for (int i = 0; i < 10; i ++) {
		if (flag) {
			if (minn[i] == -1)
				continue;
			now[len ++] = i;
			int kkk = dfs(n - minn[i], k - 1, false);
			// printf("\t%d %d %d -> %d -> %d %d -> %d | len = %d\n", n, k, flag, i, n - minn1[i], k - 1, kkk, len);
			if (kkk != -1) {
				return 1;
			}
		} else {
			if (minn1[i] == -1)
				continue;
			now[len ++] = i;
			int kkk = dfs(n - minn1[i], k - 1, false);
			// printf("\t%d %d %d -> %d -> %d %d -> %d | len = %d\n", n, k, flag, i, n - minn1[i], k - 1, kkk, len);
			if (kkk != -1) {
				return 1;
			}
		}
	}
	len --;
	return -1;
}

int main () {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		int kkk = dfs(n, (n + 6) / 7, true);
		if (kkk == -1) {
			printf("-1\n");
			len = 0;
			continue;
		}
		for (int i = 0; i < len; i ++) {
			printf("%d", now[i]);
		}
		printf("\n");
		len = 0;
	}
	return 0;
}
