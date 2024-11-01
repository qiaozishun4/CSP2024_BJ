#include <bits/stdc++.h>
using namespace std;
const int sticks[8] = {-1, -1, 1, 7, 4, 2, 6, 8};
const int sticks0[8] = {-1, -1, 1, 7, 4, 2, 0, 8};
const int best_sticks[14] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68};
int t, n;
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        if (n < 14)  cout << best_sticks[n];
        else if (n % 7 == 0) {
            n /= 7;
            for (int i = 1; i <= n; i++) {
                cout << 8;
            }
        } else {
            int tmp = (n % 7) + 7;
            n /= 7;
            n--;
            cout << best_sticks[tmp];
            for (int i = 1; i <= n; i++) {
                cout << 8;
            }
        }
        cout << endl;
    }
    return 0;
}