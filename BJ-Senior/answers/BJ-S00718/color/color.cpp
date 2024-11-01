#include <iostream>
using namespace std;
const int N = 2e5+5;
bool File;
int n,T;
int a[N];
int main() {
	File = freopen("color.in","r",stdin);
	File = freopen("color.out","w",stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		int s = 0;
		for (int i = 0;i < n;i++) {
			cin >> a[i];
		}
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < i;j++) {
				if (a[i] == a[j]) {
					s += a[i];
					break;
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}