#include <iostream>
using namespace std;
bool v[4][13],x;
int n,h,d,a = 0;
char c,s;
int main() {
	x = freopen("poker.in","r",stdin);
	x = freopen("poker.out","w",stdout);
	cin >> n;
	while (n--) {
		cin >> c >> s;
		if (c == 'D') {
			h = 0;
		} else if (c == 'C') {
			h = 1;
		} else if (c == 'H') {
			h = 2;
		} else {
			h = 3;
		}
		d = s - '1';
		if (d > 10) {
			if (s == 'T') {
				d = 9;
			} else if (s == 'J') {
				d = 10;
			} else if (s == 'Q') {
				d = 11;
			} else if (s == 'K') {
				d = 12;
			} else {
				d = 0;
			}
		}
		if (!v[h][d]) {
			v[h][d] = 1;
			a++;
		}
	}
	cout << 52 - a << endl;
	return 0;
}
