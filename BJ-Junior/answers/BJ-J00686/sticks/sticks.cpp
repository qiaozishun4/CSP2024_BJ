#include <bits/stdc++.h>
using namespace std;

long long T, n;

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n;
        if (n == 0) {
            cout << "0" << endl;
        } else if (n == 1) {
            cout << "-1" << endl;
        } else if (n == 2) {
            cout << "1" << endl;
        } else if (n == 3) {
            cout << "7" << endl;
        } else if (n == 4) {
            cout << "4" << endl;
        } else if (n == 5) {
            cout << "2" << endl;
        } else if (n == 6) {
            cout << "6" << endl;
        } else if (n % 7 == 0) {
            cout << "8";
            for (int i = 2; i <= n / 7; i++) {
                cout << "8";
            }
            cout << endl;
        } else if (n % 7 == 1) {
            cout << "10";
            for (int i = 2; i <= n / 7; i++) {
                cout << "8";
            }
            cout << endl;
        } else if (n % 7 == 2) {
            cout << "18";
            for (int i = 2; i <= n / 7; i++) {
                cout << "8";
            }
            cout << endl;
        } else if (n % 7 == 3) {
            cout << "22";
            for (int i = 2; i <= n / 7; i++) {
                cout << "8";
            }
            cout << endl;
        } else if (n % 7 == 4) {
            cout << "20";
            for (int i = 2; i <= n / 7; i++) {
                cout << "8";
            }
            cout << endl;
        } else if (n % 7 == 5) {
            cout << "28";
            for (int i = 2; i <= n / 7; i++) {
                cout << "8";
            }
            cout << endl;
        } else if (n % 7 == 6) {
            cout << "68";
            for (int i = 2; i <= n / 7; i++) {
                cout << "8";
            }
            cout << endl;
        }
    }
    return 0;
}