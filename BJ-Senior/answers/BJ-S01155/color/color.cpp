#include <iostream>
using namespace std;

typedef long long ll;
ll a[1000100];
ll t, n;

int main () {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		ll sum = 0;
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
		}
		for (int j = 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (a[j] == a[k]) {
					sum += a[j];
					break;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
