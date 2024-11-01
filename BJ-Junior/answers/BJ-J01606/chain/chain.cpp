#include <bits/stdc++.h>

using i64 = long long;
auto& IG = std::ignore;

const i64 MAXN = 2e5 + 10;

i64 n, k, q, r, c;
i64 len[MAXN], vis[MAXN];
std::vector<i64> table[MAXN];

void solve(void) {
    memset(vis, 0, sizeof(vis));
    IG = scanf("%lld%lld%lld", &n, &k, &q);
    for (i64 i = 1; i <= n; ++i) {
        i64 flag = 0;
        IG = scanf("%lld", &len[i]);
        table[i].clear();
        for (i64 j = 1; j <= len[i]; ++j) {
            i64 t = 0;
            IG = scanf("%lld", &t);
            if (flag && j - flag + 1 <= k) vis[t] = 1;
            table[i].emplace_back(t);
            if (t == 1) flag = j;
        }
    }
    while (q--) {
        IG = scanf("%lld%lld", &r, &c);
        assert(r == 1);
        if (vis[c]) {
            puts("1");
        }
        else {
            puts("0");
        }
    }
}

int main() {
    IG = freopen("chain.in", "r", stdin);
    IG = freopen("chain.out", "w", stdout);

    i64 t = 0;
    IG = scanf("%lld", &t);
    while (t--) solve();

    return 0;
}
