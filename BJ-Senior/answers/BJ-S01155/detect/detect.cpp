#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
ll t, n, m, l, v, a;
ll b[1000100];

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	for (int k = 1; k <= t; k++) {
		cin >> n >> m >> l >> v;
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a >> b[i] >> a;
			if (b[i] > v) sum++;
		}
		for (int i = 1; i <= m; i++) {
			cin >> a;
		}
		cout << sum << " " << m - 1 << endl;
	}
	return 0;
}
