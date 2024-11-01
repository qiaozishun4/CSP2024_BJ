#include <iostream>
#include <cstdio>
using namespace std;

int n, t, x;
int a[20] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288};

int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		if (n < 20) {
			cout << a[n] << "\n";
		}else {
			x = n % 7;
			if (x == 0) {
				x = n / 7;
				while (x--) {
					cout << 8;
				}
			}else if (x == 1) {
				cout << 10;
				x = n / 7;
				while (--x) {
					cout << 8;
				}
			}else if (x == 2) {
				cout << 1;
				x = n / 7;
				while (x--) {
					cout << 8;
				}
			}else if (x == 3) {
				cout << 200;
				x = n / 7 - 1;
				while (--x) {
					cout << 8;
				}
			}else if (x == 4) {
				cout << 20;
				x = n / 7;
				while (--x) {
					cout << 8;
				}
			}else if (x == 5) {
				cout << 2;
				x = n / 7;
				while (x--) {
					cout << 8;
				}
			}else {
				cout << 6;
				x = n / 7;
				while (x--) {
					cout << 8;
				}
			}
			cout << "\n";
		}
	}
	return 0;
}
