#include <bits/stdc++.h>
using namespace std;

int t, n, a[100] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 23, 26};
int co[100] = {0, 0, 1, 7, 4, 2, 6, 8};

int main() {

    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "W", stdout);

    cin >> t;
    for (int i = 1; i <= t; i ++) {
        cin >> n;
        if (n <= 1) {
            cout << -1 << endl;
            continue;
        }
        if (n <= 11) {
            cout << a[n] << endl;
            continue;
        }
        if (n % 7 == 1) {
            cout << 10;
            for (int j = 1; j <= (n / 7) - 1; j ++) cout << 8;
            cout << endl;
            continue;
        }
        if(n % 7 == 3) {
            cout << 200;
            for (int j = 1; j <= (n / 7) - 2; j ++) cout << 8;
            cout << endl;
            continue;
        }
        if(n % 7 == 4) {
            cout << 20;
            for (int j = 1; j <= (n / 7) - 1; j ++) cout << 8;
            cout << endl;
            continue;
        }
        if (n % 7 == 0) {
            for (int j = 1; j <= (n / 7); j ++) {
                cout << 8;
            }
            cout << endl;
            continue;
        }
        cout << co[n % 7];
        for (int j = 1; j <= n / 7; j ++) {
            cout << 8;
        }
        cout << endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
