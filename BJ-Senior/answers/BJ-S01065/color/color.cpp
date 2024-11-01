#include <iostream>
using namespace std;

const int NR = 2e5 + 5;
int n;
int a[NR];
int ans;
int lst[2];

void dfs(int x, int sum) {
	if (x == n + 1) {
		ans = max(ans, sum);
		return;
	}

	int tmp;
	tmp = lst[0];
	lst[0] = x;
	dfs(x+1, sum + (a[tmp] == a[x]? a[x] : 0));
	lst[0] = tmp;

	tmp = lst[1];
	lst[1] = x;
	dfs(x+1, sum + (a[tmp] == a[x]? a[x] : 0));
	lst[1] = tmp;
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i=1; i<=n; i++)
			scanf("%d", &a[i]);

		ans = 0;
		lst[0] = 1, lst[1] = 0;

		dfs(2, 0);

		printf("%d\n", ans);
	}
	return 0;
}
