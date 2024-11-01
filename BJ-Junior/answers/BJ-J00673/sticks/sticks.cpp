#include <bits/stdc++.h>
using namespace std;
const int cost[10] = {6,2,5,5,4,5,6,3,7,6};
void solve(int n) {
    if (n <= 1) {
        cout << -1 << "\n";
        return;
    }
    int len = (n + 6) / 7;
    for (int i = 1; i <= len; i++) {
        for (int j = (i == 1 ? 1 : 0); j <= 9; j++) {
            int x = n - cost[j];
            if (2 * (len - i) <= x && x <= 7 * (len - i)) {
                n = x;
                cout << j;
                break;
            }
        }
    }
    cout << "\n";
}
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        solve(n);
    }
    return 0;
}

