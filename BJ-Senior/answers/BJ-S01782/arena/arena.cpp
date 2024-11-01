#include <bits/stdc++.h>
#define int long long

using namespace std;

const int NR = 1e5 + 5;

int T, n, q, m, K, val, vis[NR], ans[NR], a[NR], b[NR], c[NR];
string s[30];
map < int, int > mp;

// inline void dfs(int x, int y, int z, int w) {
//     if (!x) {
//         if (vis[y]) return;
//         cout << "im at " << y << '\n';
//         if (y <= w) {
//             if (a[y] >= z) val += y;
//             z = min(z, a[y]);
//             int xx = x + z, yy = (y - 1) >> z;
//             if (y == 4) cout << "ch " << xx << ' ' << yy << '\n';
//             for (int i = (yy << z) + 1; i <= ((yy + 1) << z); ++i) vis[i] = 1;
//         }
//         else val += y;
//         return;
//     }
//     if (s[x][y] == '0') dfs(x - 1, y * 2 - 1, z, w), dfs(x - 1, y * 2, x, w);
//     else dfs(x - 1, y * 2, z, w), dfs(x - 1, y * 2 - 1, x, w);
// }

// inline void brute() {
//     int res = 0;
//     for (int i = 1; i <= q; ++i) {
//         int k = 1, o = 0;
//         while (k < c[i]) k *= 2, o ++;
//         for (int j = 1; j <= k; ++j) vis[j] = 0;
//         val = 0, dfs(o, 1, o, c[i]);
//         res ^= (i * val);
//         cout << "query " << c[i] << ' ' << val << '\n';
//     }
//     cout << res << '\n';
// }

// inline bool chkB() {
//     int sum = 0;
//     for (int i = 1; i <= m; ++i)
//         for (int j = 1; j < s[i].size(); ++j) sum += s[i][j] - '0';
//     if (!sum) return 1;
//     return 0;
// }

inline int dfs(int x, int y) {
    if (!x) return y;
    if (s[x][y] == '0') {
        int t = dfs(x - 1, y * 2 - 1);
        if (a[t] >= x) return t;
        return dfs(x - 1, y * 2);
    }
    int t = dfs(x - 1, y * 2);
    if (a[t] >= x) return t;
    return dfs(x - 1, y * 2 - 1);
}

inline void A() {
    int res = 0;
    for (int i = 1; i <= q; ++i) {
        if (mp[c[i]]) res ^= (i * mp[c[i]]);
        int k = 1, o = 0;
        while (k < c[i]) k *= 2, o ++;
        for (int j = 1; j <= k; ++j) vis[j] = 0;
        int t = dfs(o, 1);
        res ^= (i * t), mp[c[i]] = t;
        // cout << "query " << c[i] << ' ' << val << '\n';
    }
    cout << res << '\n';
}

// inline void B() {

// }

inline void solve() {
    int X[10]; cin >> X[0] >> X[1] >> X[2] >> X[3];
    for (int i = 1; i <= n; ++i) a[i] = b[i] ^ X[i % 4];
    // if (n <= 5000 && q <= 5000) brute();
    // else if (chkB()) B();
    // else A();
    A();
}

signed main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    ios :: sync_with_stdio(false), cin.tie(0);
    cin >> n >> q, K = 1, m = 0;
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= q; ++i) cin >> c[i];
    while (K < n) K *= 2, m ++;
    for (int i = 1; i <= m; ++i) cin >> s[i], s[i] = " " + s[i];
    cin >> T;
    while (T --) solve();
    return 0;
}