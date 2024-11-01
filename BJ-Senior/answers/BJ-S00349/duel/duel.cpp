#include <bits/stdc++.h>
#define i64 long long

const i64 MAXN = 1e6 + 64;

i64 a[MAXN], n;

std::queue<i64> q;

void solve()
{
    assert(scanf("%lld", &n));
    for (i64 i = 1; i <= n; ++i) assert(scanf("%lld", &a[i]));
    std::sort(a + 1, a + 1 + n, std::less<i64>());
    for (i64 i = 1; i <= n; ++i)
    {
        if (!q.empty() && a[i] > q.front()) q.pop();
        q.push(a[i]);
    }
    printf("%lld\n", (i64)q.size());
}

signed main()
{
    assert(freopen("duel.out", "w", stdout));
    assert(freopen("duel.in", "r", stdin));
    solve();
    return 0;
}
