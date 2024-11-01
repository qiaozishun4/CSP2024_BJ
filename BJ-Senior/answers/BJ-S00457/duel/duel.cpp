#include <bits/stdc++.h>
using namespace std;
int n, a[100010], r = 0;
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 1; i < n; i++)
		if (a[i] > a[r])
			r++;
	cout << n - r;
	return 0;
}
