#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char c[1005][1005];

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k, x0, y0, d0, ans = 0;
        cin >> n >> m >> k >> x0 >> y0 >> d0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j) cin >> c[i][j];
        }
        c[x0][y0] = 'a';
        for (int i = 1; i <= k; ++i)
        {
            int xxx = x0, yyy = y0;
            if (d0 == 0) yyy = y0 + 1;
            else if (d0 == 1) xxx = x0 + 1;
            else if (d0 == 2) yyy = y0 - 1;
            else if (d0 == 3) xxx = x0 - 1;
            if (1 <= xxx && xxx <= n && 1 <= yyy && yyy <= m && c[xxx][yyy] != 'x')
            {
                x0 = xxx;
                y0 = yyy;
                c[x0][y0] = 'a';
            }
            else
            {
                c[x0][y0] = 'a';
                d0 = (d0 + 1) % 4;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (c[i][j] == 'a') ++ans;
            }
        }
        cout << ans;
    }
    return 0;
}
