#include <bits/stdc++.h>
#define int long long

using namespace std;

const int NR = 2e5 + 5;
const int MR = 1e6 + 5;

int T, n, ans, res, cur, a[NR], b[NR], f[NR], g[MR];

inline void solve() {
    cin >> n, ans = 0, res = 0, cur = -1e18;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i] * (a[i] == a[i - 1]), ans += b[i];
        g[a[i]] = -1e18;
    }
    for (int i = 1; i <= n; ++i) {
        f[i] = 0;
        f[i] = max(f[i], g[a[i]] + a[i] - b[i]);
        f[i] = max(f[i], cur - b[i]);
        g[a[i - 1]] = max(g[a[i]], f[i] - b[i]);
        cur = max(cur, f[i] - b[i]);
        res = max(res, f[i]);
    }
    cout << ans + res << '\n';
}

signed main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios :: sync_with_stdio(false), cin.tie(0);
    cin >> T;
    while (T --) solve();
    return 0;
}