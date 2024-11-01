//HMZ于东方升起，如利剑般驱散黑暗，撒遍光明，化解迷茫，指引道路，构筑世界之真理！
#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, ans = 0, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	for (int i = 100000; i >= 1; i--) {
		ans = max(ans, a[i]);
	}
	cout << ans;
	return 0;
}