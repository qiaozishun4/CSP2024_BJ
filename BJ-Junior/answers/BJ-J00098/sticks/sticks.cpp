#include <bits/stdc++.h>
using namespace std;

int t, n;
int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main () {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    for (int j = 1; j <= t; ++j) {
        cin >> n;
        int i = 0;
        while (++i) {
            int ans = 0, x = i;
            while (x > 0) {
                ans += num[x % 10];
                x /= 10;
            }
            if (ans == n) {
                cout << i <<"\n";
                break;
            }
            if (i > pow(n, 10)) {
                cout << -1 << "\n";
                break;
            }
        }
    }
    return 0;
}
