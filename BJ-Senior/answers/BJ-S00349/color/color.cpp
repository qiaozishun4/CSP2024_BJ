#include <bits/stdc++.h>
#define i64 long long

const i64 MAXN = 2e5 + 64;

i64 A[MAXN], n;

i64 co[MAXN], g[2], tot, mx;

void solve()
{
    assert(scanf("%lld", &n)), mx = 0;
    for (i64 i = 1; i <= n; ++i) assert(scanf("%lld", &A[i]));
    for (i64 st = 0; st < (1ll << n); ++st)
    {
        for (i64 i = 1; i <= n; ++i)
            co[i] = !!(1ll << (i - 1) & st);
        g[0] = 0, g[1] = 0, tot = 0;
        for (i64 i = 1; i <= n; ++i)
        {
            if (A[g[co[i]]] == A[i])
            {
                tot = tot + A[i];
            }
            g[co[i]] = i;
        }
        mx = std::max(mx, tot);
    }
    printf("%lld\n", mx);
}

i64 T;

signed main()
{
    assert(freopen("color.out", "w", stdout));
    assert(freopen("color.in", "r", stdin));
    assert(scanf("%lld", &T));
    while (T--) solve();
    return 0;
}

/*
2
15
5 3 7 2 4 13 11 6 5 5 3 5 12 8 13
15
1 12 11 11 7 11 15 6 4 6 3 15 7 5 2

5
19

*/
