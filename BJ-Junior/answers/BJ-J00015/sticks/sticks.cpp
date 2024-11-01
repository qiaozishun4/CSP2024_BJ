#include <bits/stdc++.h>
using namespace std;

int c[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        if (n % 7 == 0) {
            for (int i = 1; i <= n / 7; i++) {
                cout << "8";
            }
            cout << "\n";
        } else if (n == 1) cout << "-1\n";
        else if ((n - 1) % 7 == 0) {
            cout << "10";
            for (int i = 1; i < n / 7; i++) {
                cout << "8";
            }

            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
