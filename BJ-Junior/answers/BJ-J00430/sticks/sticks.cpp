#include <bits/stdc++.h>
#define i64 long long

const i64 MAXN = 1e3 + 64;

const std::vector<i64> C = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

i64 n, m;

i64 cost(i64 x)
{
    i64 tot = 0;
    while (x)
    {
        tot += C[x % 10];
        x = x / 10;
    }
    return tot;
}

void solve()
{
    std::cin >> n;
    for (i64 i = 1; i < 1e6; ++i)
    {
        if (cost(i) == n)
        {
            std::cout << i << '\n';
            return;
        }
    }
    return puts("-1"), void();
}

i64 T;

signed main()
{
    freopen("sticks.out", "w", stdout);
    freopen("sticks.in", "r", stdin);
    std::cin >> T;
    while (T--) solve();
    return 0;
}
