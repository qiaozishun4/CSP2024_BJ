#include <bits/stdc++.h>
using namespace std;

int T,n,num[] = {6,2,5,5,4,5,6,3,7,6},p,q,t;

int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		if (n <= 1) {cout << -1 << endl;continue;}
		p = n / 7,q = n % 7,t = 1;
		if (!q) {
			for (int i = 1;i <= p;i++) cout << 8;
			cout << endl;
			continue;
		}
		if (!p) {
			if (q == 2) cout << 1;
			if (q == 3) cout << 7;
			if (q == 4) cout << 4;
			if (q == 5) cout << 2;
			if (q == 6) cout << 6;
			cout << endl;
			continue;
		}
		for (int i = 1;i <= 9;i++)
			if (num[i] >= q) {
				cout << i;
				q = num[i] - q;
				break;
			}
		while (q && t < p) {
			q--,t++;
			cout << 0;
		}
		if (q == 1) cout << 0;
		if (q == 2) cout << 2;
		if (q == 3) cout << 4;
		if (q == 4) cout << 7;
		if (q == 5) cout << 1;
		if (!q)
			for (int i = t;i <= p;i++) cout << 8;
		cout << endl;
	}
	return 0;
}