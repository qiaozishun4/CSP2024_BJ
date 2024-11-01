

#include <bits/stdc++.h>

using namespace std;

int num,k,q;
int a[1009][10009];

bool check (int x) {
	for (int i = 1; i <= num; i++) {
		for (int j = 2; j <= a[i][1]-k; i++) {
			if (a[i][j]!=1) {
				continue;
			}
			for (int k = j; k < j+k; k++) {
				if (a[i][k] == x) {
					return true;
				}
			}
		}
	}
	return false;
}

int main () {
	freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
	int Ti = 0;
	cin >> Ti;
	while (cin >> Ti) {
		cin >> num >> k >> q;
		for (int i = 1; i <= num; i++) {
			int x = 0;
			cin >> a[i][1];
			for (int j = 2; j <= a[i][1]; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= q; i++) { 
			int x, y;
			cin >> x >> y;
			if (check(y)) {
				cout << 1 << endl;
				continue;
			}
			cout << 0 << endl;
		}
	}
	
	return 0;
}
