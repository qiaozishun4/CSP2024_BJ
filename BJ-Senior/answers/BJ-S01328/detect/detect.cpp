#include <bits/stdc++.h>

using i64 = long long;
auto& IG = std::ignore;


const i64 MAXN = 1e5 + 10, MAXL = 1e6 + 10, INF = 0x3f3f3f3f3f3f3f3f;

i64 n, m, l, v;
i64 dr[MAXN], vr[MAXN], ar[MAXN], pr[MAXN], can[MAXN];

i64 check(i64 mark) {
    for (i64 i = 0; i < n; ++i) can[i] = 0;
    i64 res = 0;
    for (i64 i = 0; i < m; ++i) {
        if (mark >> i & 1) {
            for (i64 j = 0; j < n; ++j) {
                if (dr[j] < pr[i]) continue;
                assert(dr[j] >= pr[i]);
                i64 now = vr[j] * vr[j] + 2 * ar[j] * (pr[i] - dr[j]);
                if (now * now > v * v) {
//                    printf("d[%lld]=%lld, p[%lld]=%lld ", j, dr[j], i, pr[i]);
                    can[j] = 1;
                }
            }
        }
    }
//    puts("");
    for (i64 i = 0; i < n; ++i) res += can[i];
    return res;
}

void solve(void) {
    IG = scanf("%lld%lld%lld%lld", &n, &m, &l, &v);
    for (i64 i = 0; i < n; ++i) {
        IG = scanf("%lld%lld%lld", &dr[i], &vr[i], &ar[i]);
    }
    for (i64 i = 0; i < m; ++i) {
        IG = scanf("%lld", &pr[i]);
    }
    i64 ans1 = check((1 << m) - 1), ans2 = INF;
    for (i64 mark = 1; mark < (1 << m); ++mark) {
        if (ans1 == check(mark)) {
//            printf("mark: %lld\n", mark);
            ans2 = std::min(ans2, (i64) __builtin_popcountll(mark));
        }
    }
    printf("%lld %lld\n", ans1, ans2);
}

int main() {
    IG = freopen("detect.in", "r", stdin);
    IG = freopen("detect.out", "w", stdout);

    i64 t = 0;
    IG = scanf("%lld", &t);
    while (t--) solve();

    return 0;
}
