#include <bits/stdc++.h>
#define int long long

using namespace std;

const int NR = 1e5 + 5;

int T, n, m, ans, L, V, p[NR];
pair < int, int > b[NR], c[NR];

struct F {
    int x, y;
    F operator * (const F &rhs) const {
        F res;
        res.x = x * rhs.x, res.y = y * rhs.y;
        return res;
    }
    F operator + (const F &rhs) const {
        F res;
        res.y = y * rhs.y, res.x = x * rhs.y + y * rhs.x;
        return res;
    }
    inline int lb() {
        if (x % y == 0) return x / y - 1;
        return x / y;
    }
    inline int ub() {
        return x / y + 1;
    }
};

inline F tof(int x, int y) {
    F res;
    res.x = x, res.y = y;
    return res;
}

inline bool cmp(const pair < int, int > &x, const pair < int, int > &y) {
    if (x.second != y.second) return x.second < y.second;
    return x.first > y.first;
}

inline void solve() {
    cin >> n >> m >> L >> V;
    for (int i = 1; i <= n; ++i) {
        int d, v, a; cin >> d >> v >> a;
        if (a > 0) {
            if (v > V) b[i] = make_pair(d, L);
            else {
                F t; t.x = V - v, t.y = a;
                F pos = tof(d, 1) + tof(v, 1) * t + tof(a, 2) * t * t;
                b[i] = make_pair(pos.ub(), L);
            }
        }
        else if (a == 0) {
            if (v > V) b[i] = make_pair(d, L);
            else b[i] = make_pair(L + 1, L);
        }
        else {
            if (v <= V) b[i] = make_pair(L + 1, L);
            else {
                F t; t.x = v - V, t.y = -a;
                F pos = tof(d, 1) + tof(v, 1) * t + tof(a, 2) * t * t;
                b[i] = make_pair(d, min(L, pos.lb()));
            }
        }
    }
    for (int i = 1; i <= m; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i) {
        if (b[i].first > b[i].second) continue;
        int t = lower_bound(p + 1, p + m + 1, b[i].first) - p;
        if (t <= m && p[t] <= b[i].second) c[++ ans] = b[i];
    }
    cout << ans << ' ', n = 0;
    sort(c + 1, c + ans + 1, cmp);
    for (int i = 1, mx = 0; i <= ans; ++i) {
        if (mx >= c[i].first) continue;
        mx = max(mx, c[i].first), b[++ n] = c[i];
    }
    ans = 0;
    for (int i = 1, lst = 0; i <= n; ++i) {
        if (lst >= b[i].first && lst <= b[i].second) continue;
        ans ++, lst = p[upper_bound(p + 1, p + m + 1, b[i].second) - p - 1];
    }
    cout << m - ans << '\n', ans = 0;
}

signed main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios :: sync_with_stdio(false), cin.tie(0);
    cin >> T;
    while (T --) solve();    
    return 0;
}