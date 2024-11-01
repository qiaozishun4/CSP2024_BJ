#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[15];
int main () {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    a[0] = 6;
    a[1] = 2;
    a[2] = 5;
    a[3] = 5;
    a[4] = 4;
    a[5] = 5;
    a[6] = 6;
    a[7] = 3;
    a[8] = 7;
    a[9] = 6;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        if (n == 8) {
            cout << 10 << endl;
            continue;
        }
        else if ((n - 1) % 7 == 0 && n > 9) {
            cout << 10;
            for (int i = 1; i < (n - 1) / 7; i++) {
                cout << 8;
            }
            cout << endl;
            continue;
        }
        else if (n % 7 == 0) {
            for (int i = 1; i <= n / 7; i++) {
                cout << 8;
            }
            cout << endl;
            continue;
        }
        else if (n < 2) {
            cout << -1 << endl;
            continue;
        }
        else if (n == 2) {
            cout << 1 << endl;
        }
        else if (n == 3) {
            cout << 7 << endl;
        }
        else if (n == 4) {
            cout << 4 << endl;
        }
        else if (n == 5) {
            cout << 2 << endl;
        }
        else if (n == 6) {
            cout << 6 << endl;
        }
        else if (n == 7) {
            cout << 8 << endl;
        }
        else if (n == 9) {
            cout << 18 << endl;
        }
        else if (n == 10) {
            cout << 22 << endl;
        }
        else if (n == 11) {
            cout << 20 << endl;
        }
        else if (n == 12) {
            cout << 28 << endl;
        }
        else if (n == 13) {
            cout << 68 << endl;
        }
        else if (n == 14) {
            cout << 88 << endl;
        }
        else if (n <= 20 && n > 14) {
            bool man = 0;
            for (int i = 1; i <= 9; i++) {
                for (int j = 0; j <= 9; j++) {
                    for (int k = 0; k <= 9; k++) {
                        if (a[i] + a[j] + a[k] == n) {
                            cout << i * 100 + j * 10 + k;
                            if (k == 0) cout << 0;
                            cout << endl;
                            man = 1;
                            break;
                        }
                    }
                    if (man) break;
                }
                if (man) break;
            }
            continue;
        }
        else {
            cout << -1 <<endl;
        }
    }
    return 0;
}

