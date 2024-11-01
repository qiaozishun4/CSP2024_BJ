#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5, INF = 1e9;

int n, m, L, V, cnt;
int p[MAXN], sum[MAXN];
bool vis[MAXN];

int S(int l, int r) {
    if (l == 0) return sum[r];
    return sum[r] - sum[l - 1];
}

struct Segment {
    int l, r;
} s[MAXN];

void init() {
    cnt = 0;
    for (int i = 0; i <= L; i++) {
        sum[i] = 0;
    }
}

int work() {
    int ret = INF;
    for (int i = 0; i < (1 << m); i++) {
        for (int j = 1; j <= n; j++) 
            vis[j] = false;
        for (int j = 1; j <= m; j++) {
            if (!(i >> (j - 1) & 1)) continue;
            for (int k = 1; k <= n; k++) {
                if (s[k].l <= p[j] && p[j] <= s[k].r)
                    vis[k] = true;
            }
        }
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            cnt += vis[j];
        }
        if (cnt < n) continue;
        ret = min(ret, __builtin_popcount(i));
    }
    return ret;
}

void solve() {
    scanf("%d%d%d%d", &n, &m, &L, &V);
    bool flag = true;
    for (int i = 1, d, a, v; i <= n; i++) {
        scanf("%d%d%d", &d, &v, &a);
        if (a == 0) {
            if (v <= V) continue;
            else s[++cnt] = {d, L};
        } else if (a > 0) {
            if (v > V) s[++cnt] = {d, L};
            else {
                int x = (V * V - v * v) / (2 * a) + 1;
                if (d + x <= L) s[++cnt] = {d + x, L};
            }
        } else {
            if (v <= V) continue;
            else {
                int x = (v * v - V * V + (-2 * a) - 1) / (-2 * a) - 1;
                s[++cnt] = {d, min(d + x, L)};
                if (d + x < L) flag = false;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &p[i]);
        sum[p[i]]++;
    }
    for (int i = 1; i <= L; i++) {
        sum[i] += sum[i - 1];
    }
    int ans = 0;
    n = 0;
    for (int i = 1; i <= cnt; i++) {
        if (S(s[i].l, s[i].r) == 0) continue;
        ans += 1;
        s[++n] = s[i];
    }
    if (flag) {
        if (n == 0) printf("%d %d\n", ans, m);
        else printf("%d %d\n", ans, m - 1);
    } else {
        int res = 0;
        if (n) res = work();
        printf("%d %d\n", ans, m - res);
    }
    init();
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T = 1;
    scanf("%d", &T);
    while (T--) solve();
}

// g++ detect.cpp -o detect -std=c++14 -O2 -static && ./detect