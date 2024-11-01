#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int red, blue;
int t, n, a[200010];
void dfs(int x, int num, int col) {
	// cout << x << " " << num << " " << col << endl;
	if (x == n + 1) {
		ans = max(ans, num);
		return;
	}
	if (col) {
		int tmp = red;
		int p = (a[red] == a[x]) ? (num + a[x]) : (num);
		red = x;
		dfs(x + 1, p, 0);
		red = x;
		dfs(x + 1, p, 1);
		red = tmp;
	} else {
		int tmp = blue;
		int p = (a[blue] == a[x]) ? (num + a[x]) : (num);
		blue = x;
		dfs(x + 1, p, 0);
		blue = x;
		dfs(x + 1, p, 1);
		blue = tmp;
	}
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		red = blue = 0;
		dfs(1, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
