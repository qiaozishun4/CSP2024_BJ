#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int r[maxn];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    sort(r + 1, r + n + 1);
    int cur_target = 1;
    for (int i = 2; i <= n; i++) {
        if (r[i] > r[cur_target]) {
            cur_target++;
        }
    }
    cout << n - cur_target + 1 << endl;
    return 0;
}
