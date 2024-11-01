#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    ll m[20] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
    ll t, n, tmp, sum, f;
    cin >> t;
    while (t--) {
        cin >> n;
        f = 1;
        for (ll i = 0; i <= 100000; i++) {
            tmp = i;
            sum = 0;
            while (tmp) {
                sum += m[tmp % 10];
                tmp /= 10;
            }
            if (sum == n) {
                cout << i << '\n';
                f = 0;
                break;
            }
        }
        if (f) {
            cout << "-1\n";
        }
    }

    return 0;
}
