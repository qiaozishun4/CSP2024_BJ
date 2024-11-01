#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	sort(a + 1, a + n + 1);
	int lst = 1;
	for (int i = 1; i <= n; i ++ )
		if (a[i] > a[lst]) lst ++;
	cout << n - lst + 1 << '\n';
	return 0;
}
