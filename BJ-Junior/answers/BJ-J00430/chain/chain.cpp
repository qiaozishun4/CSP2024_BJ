#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define i64i64 std::pair<i64, i64>
#define i64 long long

const i64 MAXN = 1e4 + 64, MAXL = 2e5 + 64;

i64 n, k, q;

i64 S[MAXN][128];
i64 rin[MAXN];

i64 c;

bool dfs(i64 p, i64 pre, i64 dep)
{
    if (!dep) return false;
    i64 i = 1;
    for (; i <= rin[p]; ++i) if (S[p][i] == pre) break;
    for (++i; i <= rin[p]; ++i)
    {
        if (dep == 1 && S[p][i] == c) return true;
        for (i64 j = 1; j <= n; ++j)
        {
            if (j == p) continue;
            if (dfs(j, S[p][i], dep - 1))
            {
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    memset(S, 0, sizeof(S));
    memset(rin, 0, sizeof(rin));
    c = 0;
    std::cin >> n >> k >> q;
    for (i64 i = 1; i <= n; ++i)
    {
        std::cin >> rin[i];
        for (i64 j = 1; j <= rin[i]; ++j) std::cin >> S[i][j];
    }
    for (i64 r, fl; q--; )
    {
        fl = 0;
        std::cin >> r >> c;
        for (i64 i = 1; i <= n; ++i)
        {
            if (dfs(i, 1, r))
            {
                puts("1");
                fl = 1;
                break;
            }
        }
        if(!fl) puts("0");
    }
}

i64 T;

signed main()
{
    freopen("chain.out", "w", stdout);
    freopen("chain.in", "r", stdin);
    std::cin >> T;
    while (T--) solve();
    return 0;
}

// orz