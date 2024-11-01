#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll use[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
ll T, n;

ll digit_split_sum(ll x) {
    ll ans = 0;
    while (x != 0) {
        ll digit = x % 10;
        ans += use[digit];
        x /= 10;
    }
    return ans;
}
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n;
        if (n < 2) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 1; ; i++) {
            if (digit_split_sum(i) == n) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
