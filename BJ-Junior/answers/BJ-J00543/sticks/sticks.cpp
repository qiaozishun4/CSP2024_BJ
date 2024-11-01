#include <bits/stdc++.h>
using namespace std;
int T, n, cnt[6] = {1, 7, 4, 2, 0, 8};
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        if (n == 6) {cout << 6 << '\n'; continue;}
        if (n == 1) {cout << -1 << '\n'; continue;}
        if (n % 7 == 0) {
            for (int i = 1; i <= n / 7; i++) cout << 8 << '\n';
            continue;
        }
        if (n % 7 == 1) {
            cout << 10 << '\n';
            for (int i = 1; i <= n / 7 - 1; i++) cout << 8 << '\n';
            continue;
        }
        if (n < 7) {cout << cnt[n - 2] << '\n'; continue;}
        int l = n / 7 + 1;
        for (int i = 1; i <= l; i++) {
            if (n - (l - i) * 7 == 2) cout << 1, n -= 2;
            else if (n - (l - i) * 7 == 3) cout << 2, n -= 5;
            else if (n - (l - i) * 7 == 4) cout << 2, n -= 5;
            else if (n - (l - i) * 7 == 5) cout << 2, n -= 5;
            else if (n - (l - i) * 7 == 6) cout << (i == 1) ? 6 : 0, n -= 6;
            else cout << 8, n -= 7;
        }
        cout << '\n';
    }
    return 0;
}