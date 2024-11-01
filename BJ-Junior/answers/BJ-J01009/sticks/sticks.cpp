#include<bits/stdc++.h>
using namespace std;
int ans[14];
int T, n;
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ans[0] = -1;
    ans[1] = -1;
    ans[2] = 1;
    ans[3] = 7;
    ans[4] = 4;
    ans[5] = 2;
    ans[6] = 6;
    ans[7] = 8;
    ans[8] = 10;
    ans[9] = 18;
    ans[10] = 22;
    ans[11] = 20;
    ans[12] = 28;
    ans[13] = 68;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n <= 13) {
            cout << ans[n] << endl;
            continue;
        }
        if (n % 7 == 0) {
            for (int i = 1; i <= n / 7; i++) {
                cout << 8;
            }
            cout << endl;
            continue;
        }
        int tmp = n % 7 + 7;
        if (tmp != 10) {
            cout << ans[tmp];
            n -= tmp;
            for (int i = 1; i <= n / 7; i++) {
                cout << 8;
            }
            cout << endl;
            continue;
        }
        tmp = 11;
        cout << ans[tmp] << 0;
        n -= tmp + 6;
        for (int i = 1; i <= n / 7; i++) {
            cout << 8;
        }
        cout << endl;
    }
    return 0;
}

