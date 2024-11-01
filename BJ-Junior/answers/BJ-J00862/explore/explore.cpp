#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t, n, m, k, i, j, x, y, d, b, c;
    cin >> t;
    for (int z = 1; z <= t; z++)
    {
        char a[1005][1005];
        bool p[1005][1005] = {0};
        int ans = 0;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        p[x][y] = 1;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                cin >> a[i][j];
        for (i = 0; i < k; i++)
        {
            b = 0;
            c = 0;
            if (d == 0)
                b = 1;
            if (d == 1)
                c = 1;
            if (d == 2)
                b = -1;
            if (d == 3)
                c = -1;
            if (x + c >= 1 && x + c <= n && y + b >= 1 && y + b <= m && a[x + c][y + b] == '.')
            {
                x += c;
                y += b;
                p[x][y] = 1;
                continue;
            }
            else
                d = (d + 1)% 4;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (p[i][j])
                    ans++;
        cout << ans << endl;
    }
    return 0;
}
