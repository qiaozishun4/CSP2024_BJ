#include <bits/stdc++.h>
using namespace std;
int a[67];
int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		if (s[0] == 'C') {
			if (s[1] == 'A') {
				if (a[1] == 0) {
					a[1]++;
					sum++;
				}
			} else if (s[1] == 'T') {
				if (a[10] == 0) {
					a[10]++;
					sum++;
				}
			} else if (s[1] == 'J') {
				if (a[11] == 0) {
					a[11]++;
					sum++;
				}
			} else if (s[1] == 'Q') {
				if (a[12] == 0) {
					a[12]++;
					sum++;
				}
			} else if (s[1] == 'K') {
				if (a[13] == 0) {
					a[13]++;
					sum++;
				}
			} else {
				if (a[s[1] - '0'] == 0) {
					a[s[1] - '0']++;
					sum++;
				}
			}
		} else if (s[0] == 'S') {
			if (s[1] == 'A') {
				if (a[14] == 0) {
					a[14]++;
					sum++;
				}
			} else if (s[1] == 'T') {
				if (a[23] == 0) {
					a[23]++;
					sum++;
				}
			} else if (s[1] == 'J') {
				if (a[24] == 0) {
					a[24]++;
					sum++;
				}
			} else if (s[1] == 'Q') {
				if (a[25] == 0) {
					a[25]++;
					sum++;
				}
			} else if (s[1] == 'K') {
				if (a[26] == 0) {
					a[26]++;
					sum++;
				}
			} else {
				if (a[s[1] - '0' + 13] == 0) {
					a[s[1] - '0' + 13]++;
					sum++;
				}
			}
		} else if (s[0] == 'H') {
			if (s[1] == 'A') {
				if (a[27] == 0) {
					a[27]++;
					sum++;
				}
			} else if (s[1] == 'T') {
				if (a[36] == 0) {
					a[36]++;
					sum++;
				}
			} else if (s[1] == 'J') {
				if (a[37] == 0) {
					a[37]++;
					sum++;
				}
			} else if (s[1] == 'Q') {
				if (a[38] == 0) {
					a[38]++;
					sum++;
				}
			} else if (s[1] == 'K') {
				if (a[39] == 0) {
					a[39]++;
					sum++;
				}
			} else {
				if (a[s[1] - '0' + 26] == 0) {
					a[s[1] - '0' + 26]++;
					sum++;
				}
			}
		} else {
			if (s[1] == 'A') {
				if (a[40] == 0) {
					a[40]++;
					sum++;
				}
			} else if (s[1] == 'T') {
				if (a[49] == 0) {
					a[49]++;
					sum++;
				}
			} else if (s[1] == 'J') {
				if (a[50] == 0) {
					a[50]++;
					sum++;
				}
			} else if (s[1] == 'Q') {
				if (a[51] == 0) {
					a[51]++;
					sum++;
				}
			} else if (s[1] == 'K') {
				if (a[52] == 0) {
					a[52]++;
					sum++;
				}
			} else {
				if (a[s[1] - '0' + 39] == 0) {
					a[s[1] - '0' + 39]++;
					sum++;
				}
			}
		}
		
	}
	cout << 52 - sum << endl;
	return 0;
}

