#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool F;
int T,n;
int a[8] = {-1,-1,1,7,4,2,0,8};
vector<int> b;
int main() {
	F = freopen("sticks.in","r",stdin);
	F = freopen("sticks.out","w",stdout);
	cin >> T;
	while (T--) {
		b.clear();
		cin >> n;
		if (n < 8) {
			if (n == 6) {
				cout << 6 << endl;
			} else {
				cout << a[n] << endl;
			}
			continue;
		}
		for (int i = 7;i > 1;i--) {
			while (n >= i) {
				n -= i;
				b.push_back(a[i]);
			}
		}
		if (n == 0) {
			sort(b.begin(),b.end());
			if (b[0] == 4 && b[1] == 8) {
				b[0] = 2;
				b[1] = 0;
			}
			if (b[0] == 7 && b[1] == 8) {
				b[0] = 4;
				b[1] = 0;
			}
			if (b[0] == 0) {
				int x;
				for (int i = 1;i < b.size();i++) {
					if (b[i] != 0) {
						x = i;
						break;
					}
				}
				if (b[x] != 0) {
					swap(b[x],b[0]);
				} else {
					b[0] = 6;
				}
			}
			for (int i = 0;i < b.size();i++) {
				cout << b[i];
			}
			cout << endl;
			continue;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}
