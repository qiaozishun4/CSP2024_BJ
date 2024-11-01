#include <bits/stdc++.h>
using namespace std;
int sticks[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int min_num[] = {-1, -1, 1, 7, 4, 2, 0, 8};
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n <= 1) {
            cout << -1 << endl;
            continue;
        }
        if (n <= 7) {
            cout << (n == 6 ? 6 : min_num[n]) << endl;
            continue;
        }
        if (n % 7 == 0) {
            for (int i = 1; i <= n / 7; i++) {
                cout << 8;
            }
            cout << endl;
            continue;
        }
        int left = n % 7, first = 0;
        for (int i = 1; i <= 9; i++) {
            if (sticks[i] >= left) {
                first = i;
                break;
            }
        }
        int second = min_num[7 - sticks[first] + left];
        cout << first << second;
        n -= left + 7;
        for (int i = 1; i <= n / 7; i++) {
            cout << 8;
        }
        cout << endl;
    }
    return 0;
}
