#include <bits/stdc++.h>
using namespace std;

int T, n, a[101], maxn = 0;

void dfs(int i, int lastRed, int lastBlue, int sum) {
	if (i == n) {
		if (a[i] == a[lastRed]) sum += a[i];
		if (a[i] == a[lastBlue]) sum += a[i];
		maxn = max(maxn, sum);
		return;
	}
	
	int add;
	
	add = 0;
	if (a[i] == a[lastRed]) add = a[i];
	sum += add;
	dfs(i + 1, i, lastBlue, sum);
	sum -= add;
	
	add = 0;
	if (a[i] == a[lastBlue]) add = a[i];
	sum += add;
	dfs(i + 1, lastRed, i, sum);
	sum -= add;
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> T;
	while (T > 0) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		a[0] = -1;
		dfs(1, 1, 0, 0);
		dfs(1, 0, 1, 0);
		cout << maxn << endl;
		T--;
	}
	return 0;
}
