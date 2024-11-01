#include <bits/stdc++.h>
#define i64 long long

const i64 MAXN = 1e3 + 64;

const std::vector<i64> DX = {0, 1, 0, -1};
const std::vector<i64> DY = {1, 0, -1, 0};

i64 n, m, k;

char mc[MAXN][MAXN];

i64 x, y, d;

i64 vis[MAXN][MAXN];

void solve()
{
    memset(vis, 0, sizeof(vis));
    std::cin >> n >> m >> k;
    std::cin >> x >> y >> d;
    for (i64 i = 1; i <= n; ++i)
    {
        for (i64 j = 1; j <= m; ++j)
        {
            std::cin >> mc[i][j];
        }
    }
    i64 cnt = vis[x][y] = 1;
    while (k--)
    {
        i64 nx = x + DX[d], ny = y + DY[d];
        if (nx < 1 || nx > n || ny < 1 || ny > m || mc[nx][ny] == 'x')
        {
            d = (d + 1) % 4;
        }
        else
        {
            x = nx, y = ny;
            if (!vis[x][y]) ++cnt;
            vis[x][y] = 1;
        }
    }
    std::cout << cnt << '\n';
}

i64 T;

signed main()
{
    freopen("explore.out", "w", stdout);
    freopen("explore.in", "r", stdin);
    std::cin >> T;
    while (T--) solve();
    return 0;
}
