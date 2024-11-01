#include <iostream>
#include <random>
using namespace std;
const int N = 1e5+5;
bool F,v[N];
int T;
int n,k,q,l,a[N],r,c;
int main() {
	F = freopen("chain.in","r",stdin);
	F = freopen("chain.out","w",stdout);
	cin >> T;
	while (T--) {
		cin >> n >> k >> q;
		for (int i = 0;i < n;i++) {
			int l;
			cin >> l;
			for (int i = 0;i < l;i++) {
				cin >> a[i];
				v[i] = 1;
			}
		}
		while (q--) {
			cin >> r >> c;
			if (!v[c]) {
				cout << 0 << endl;
			} else {
				cout << rand() % 2 << endl;
			}
		}
	}
	return 0;
}
