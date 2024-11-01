#include <bits/stdc++.h>
#define i64 long long

i64 f[256], g[256];

char a, b;

i64 vis[4][13], n;

void solve()
{
    std::cin >> n;
    f['D'] = 0, f['C'] = 1, f['H'] = 2, f['S'] = 3;
    g['A'] = 0, g['2'] = 1, g['3'] = 2, g['4'] = 3, g['5'] = 4, g['6'] = 5, g['7'] = 6, g['8'] = 7, g['9'] = 8, g['T'] = 9, g['J'] = 10, g['Q'] = 11, g['K'] = 12;
    for (i64 i = 1; i <= n; ++i)
    {
        std::cin >> a >> b;
        vis[f[a]][g[b]] = 1;
    }
    i64 tot = 0;
    for (i64 i = 0; i < 4; ++i)
        for (i64 j = 0; j < 13; ++j)
            if (!vis[i][j]) ++tot;
    std::cout << tot << '\n';
}

signed main()
{
    freopen("poker.out", "w", stdout);
    freopen("poker.in", "r", stdin);
    solve();
    return 0;
}
