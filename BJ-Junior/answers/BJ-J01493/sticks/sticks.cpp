#include <bits/stdc++.h>
using namespace std;

int t, i, n, j, a[20] = {
    -1, 1, 7, 4, 2, 6, 8, 10, 18, 22,
    20, 28, 68, 88, 108, 188, 200, 208, 288, 688
};
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n;
        if (n <= 20) {
            cout << a[n - 1] << endl;
        } else if (n % 7 == 0) {
            for (j = 0; j < n / 7; j++) {
                cout << 8;
            }
            cout << endl;
        } else if (n % 7 == 1) {
            cout << 10;
            for (j = 0; j < n / 7 - 1; j++) {
                cout << 8;
            }
            cout << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
