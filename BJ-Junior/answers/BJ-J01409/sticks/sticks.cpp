#include <bits/stdc++.h>
using namespace std;
const int num1[8] = {-1, -1, 1, 7, 4, 2, 6, 8};
const int num2[7] = {8, 10, 18, 22, 20, 28, 68};
int n;
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        if (n <= 1) cout << -1 << '\n';
        else if (n <= 7) cout << num1[n] << '\n';
        else if (n % 7 == 3) {
            if (n == 10) cout << 22 << '\n';
            else {
                cout << 200;
                for (int i = 1; i <= (n / 7 - 2); i++) {
                    cout << 8;
                }
                cout << '\n';
            }
        } else {
            cout << num2[n % 7];
            for (int i = 1; i <= (n / 7 - 1); i++) {
                cout << 8;
            }
            cout << '\n';
        }
    }
    return 0;
}
