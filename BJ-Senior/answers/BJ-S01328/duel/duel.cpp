#include <bits/stdc++.h>

using i64 = long long;
auto& IG = std::ignore;

const i64 MAXVAL = 1e5, MAXN = 1e5 + 10;
i64 cnt[MAXN], n;

void solve(void) {
    IG = scanf("%lld", &n);
    for (i64 i = 1; i <= n; ++i) {
        i64 a = 0;
        IG = scanf("%lld", &a);
        ++cnt[a];
    }
    i64 ans = n, left = 0;
    for (i64 i = 1; i <= MAXVAL; ++i) {
        ans -= std::min(left, cnt[i]);
        left -= std::min(left, cnt[i]);
        left += cnt[i];
    }
    printf("%lld\n", ans);
}

int main() {
    IG = freopen("duel.in", "r", stdin);
    IG = freopen("duel.out", "w", stdout);

    solve();

    return 0;
}
