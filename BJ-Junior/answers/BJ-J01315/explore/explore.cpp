#include <iostream>
using namespace std;
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	int n, m, k;
	int x, y, d;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		string s[n];
		for (int j = 0; j < n; j++) {
			cin >> s[j];
		}
		int sum = 1;
		s[x - 1][y - 1] = 't';
		for (int j = 0; j < k; j++) {
			if (d == 0) {
				if (y + 1 <= m && s[x - 1][y] != 'x') {
					y += 1;
					if (s[x - 1][y - 1] == '.' ) {
						sum += 1;
					}
					s[x - 1][y - 1] = 't';
				} else {
					d = (d + 1) % 4;
				}
			} else if (d == 1) {
				if (x + 1 <= n && s[x][y - 1] != 'x') {
					x += 1;
					if (s[x - 1][y - 1] == '.' ) {
						sum += 1;
					}
					s[x - 1][y - 1] = 't';
				} else {
					d = (d + 1) % 4;
				}
			} else if (d == 2) {
				if (y - 1 >= 1 && s[x - 1][y - 2] != 'x') {
					y -= 1;
					if (s[x - 1][y - 1] == '.' ) {
						sum += 1;
					}
					s[x - 1][y - 1] = 't';
				} else {
					d = (d + 1) % 4;
				}
			} else {
				if (x - 1 >= 1 && s[x - 2][y - 1] != 'x') {
					x -= 1;
					if (s[x - 1][y - 1] == '.' ) {
						sum += 1;
					}
					s[x - 1][y - 1] = 't';
				} else {
					d = (d + 1) % 4;
				}
			}	 	
		}
		cout << sum << endl;
	}
	return 0;
}

