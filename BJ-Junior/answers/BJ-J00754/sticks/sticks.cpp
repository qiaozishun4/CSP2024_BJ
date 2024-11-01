#include <bits/stdc++.h>
using namespace std;

const int num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int sticks(int n) {
    int res = 0, dig;
    while (n) {
        dig = n % 10;
        n /= 10;
        res += num[dig];
    }
    return res;
}

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        if (n <= 1) {
            cout << -1 << '\n';
        } else if (n % 7 == 0) {
            for (int i = 0; i < n / 7; i ++) {
                cout << 8;
            }
            cout << '\n';
        } else if (n <= 56) {
            for (int i = 0; ; i ++) {
                if (sticks(i) == n) {
                    cout << i << '\n';
                    break;
                }
            }
        } else {
            if (n % 7 == 6) {
                cout << 6;
                for (int i = 0; i < n / 7; i ++) {
                    cout << 8;
                }
                cout << '\n';
            }
            if (n % 7 == 5) {
                cout << 2;
                for (int i = 0; i < n / 7; i ++) {
                    cout << 8;
                }
                cout << '\n';
            }
            if (n % 7 == 4) {
                cout << 20;
                for (int i = 1; i < n / 7; i ++) {
                    cout << 8;
                }
                cout << '\n';
            }
            if (n % 7 == 3) {
                cout << 200;
                for (int i = 2; i < n / 7; i ++) {
                    cout << 8;
                }
                cout << '\n';
            }
            if (n % 7 == 2) {
                cout << 1;
                for (int i = 0; i < n / 7; i ++) {
                    cout << 8;
                }
                cout << '\n';
            }
            if (n % 7 == 1) {
                cout << 10;
                for (int i = 1; i < n / 7; i ++) {
                    cout << 8;
                }
                cout << '\n';
            }
        }
    }
    return 0;
}
