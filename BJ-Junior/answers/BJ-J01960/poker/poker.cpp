// poker
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int cnt[1010];

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char col, num;
		cin >> col >> num;
        int x;
        if (num == 'A') x = 1;
        else if (num >= '2' && num <= '9') x = num - '0';
        else if (num == 'T') x = 10;
        else if (num == 'J') x = 11;
        else if (num == 'Q') x = 12;
        else if (num == 'K') x = 13;

        int color;
        if (col == 'D') color = 0;
        else if (col == 'C') color = 1;
        else if (col == 'H') color = 2;
        else if (col == 'S') color = 3;
		cnt[color * 13 + x]++;
	}
	int ans = 0;
	for (int i = 1; i <= 52; i++) {
        if (cnt[i] == 0) ans++;
	}
	cout << ans << endl;
	return 0;
}
