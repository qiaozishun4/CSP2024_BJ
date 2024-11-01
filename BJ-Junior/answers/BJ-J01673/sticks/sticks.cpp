#include <bits/stdc++.h>
using namespace std;
int cost[20] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, t = 0, n = 0;
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while (t > 0) {
        t--;
        cin >> n;
        bool flag = 1;
        if (n == 1) cout << -1 << endl;
        if (n == 1) continue;
        for (long long i = 1; i <= 4000000000000000000; ++i) {
            long long sum = 0, tmp = i;
            while (tmp) sum += cost[tmp % 10], tmp /= 10;
            if (sum == n) cout << i << endl;
            if (sum == n) flag = 0;
            if (sum == n) break;
        }
        if (flag) cout << -1 << endl;
    }
    return 0;
}