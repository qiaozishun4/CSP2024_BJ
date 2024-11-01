#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (n == 1) {
            cout << -1 << endl;
            continue;
        }
        if (n == 2) {
            cout << 1 << endl;
            continue;
        }
        int b = 0, pos = 7;
        while (n >= 8) {
            if (b == 0) {
                b = b * 10 + 2;
                n -= 5;
            }
            else {
                b = b * 10 + 0;
                n -= 6;
            }
        }
        if (n == 2) {
            cout << b * 10 + 1 << endl;
        }
        else if (n == 3) {
            cout << b * 10 + 7 << endl;
        }
        else if (n == 4) {
            cout << b * 10 + 4 << endl;
        }
        else if (n == 5) {
            cout << b * 10 + 2 << endl;
        }
        else if (n == 6) {
            if (b != 0) cout << b * 10 + 0 << endl;
            else cout << b * 10 + 6 << endl;
        }
        else if (n == 7) {
            cout << b * 10 + 8 << endl;
        }
    }
    return 0;
}
