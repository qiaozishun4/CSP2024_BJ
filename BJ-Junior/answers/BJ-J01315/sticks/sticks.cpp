#include <iostream>
using namespace std;
int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int n, t;
	cin >> n;
	int a[50] = {
		-1, 1, 7, 4, 2, 6, 8, 10, 18, 23, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688, 888, 111, 111, 111, 111, 111,
		111, 8888, 1111, 1111, 1111, 1111, 1111, 1111, 88888, 11111, 11111, 11111, 11111, 11111, 11111, 888888, 
		111111, 111111, 111111, 111111, 111111, 111111, 8888888
	}; 
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t < 50) {
			cout << a[t - 1] << endl;
		} else {
			for (int i = 0; i < t; i += 7) {
				cout << '7';
			}
			cout << endl;
		}
	}
	return 0;
}

