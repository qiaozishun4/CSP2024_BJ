#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		while (n > 0) {
			n -= 7;
			cout << 8;
		}
		cout << endl;
	}
	
	
	return 0;
}
