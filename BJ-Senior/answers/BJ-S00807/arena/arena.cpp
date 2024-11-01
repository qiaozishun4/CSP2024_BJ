#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005], b[100005], s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    int r = 1;
    while (r < n) {
        r *= 2;
    }
    for (int i = 1; i <= r - n; i++) cin >> s;
    int T; cin >> T;
    while (T--) {
        int x1, x2, x3, x4; cin >> x1 >> x2 >> x3 >> x4;
        int num = x1 + x2 + x3 + x4, ans = 0;
        for (int i = 1; i <= num; i++) {
            ans = ans ^ (rand() % r);
        }
        cout << ans << "\n";
    }
    return 0;
}
