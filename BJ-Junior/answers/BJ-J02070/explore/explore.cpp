#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out","w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, k, x, y, d, ans = 0;
        char e[1005][1005];
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> e[i][j];
            }
        }
        while (k)
        {
            if (x <=n && y + 1 <=m)
            {
                if (e[x][y + 1] == '.')
                {
                    if (d == 0)
                    {
                        y++;
                        d = 1;
                        k -= 4;
                        ans++;
                    }
                    if (d == 1)
                    {
                        y++;
                        k--;
                        ans++;
                    }
                    if (d == 2)
                    {
                        y++;
                        d = 1;
                        k -= 2;
                        ans++;
                    }
                    if (d == 3)
                    {
                        y++;
                        d = 1;
                        k -= 3;
                        ans++;
                    }
                }

            }
            if (x + 1 <= n && y <= m)
            {
                if (e[x + 1][y] == '.')
                {
                    if (d == 0)
                    {
                        x++;
                        k--;
                        ans++;
                    }
                    if (d == 1)
                    {
                        x++;
                        d = 0;
                        k -= 4;
                        ans++;
                    }
                    if (d == 2)
                    {
                        x++;
                        d = 0;
                        k -= 3;
                        ans++;
                    }
                    if (d == 3)
                    {
                        x++;
                        d = 0;
                        k -= 2;
                        ans++;
                    }
                }
            }
            if (x <= n && y - 1 <= m)
            {
                if (e[x][y - 1] == '.')
                {
                    if (d == 0)
                    {
                        y--;
                        d = 1;
                        k -= 2;
                        ans++;
                    }
                    if (d == 1)
                    {
                        y--;
                        k--;
                        ans++;
                    }
                    if (d == 2)
                    {
                        y--;
                        d = 1;
                        k -= 4;
                        ans++;
                    }
                    if (d == 3)
                    {
                        y--;
                        d = 1;
                        k -= 3;
                        ans++;
                    }
                }
            }
            if (x - 1 <= n && y <= m)
            {
                if (e[x - 1][y] == '.')
                {
                    if (d == 0)
                    {
                        x--;
                        d = 2;
                        k -= 3;
                        ans++;
                    }
                    if (d == 1)
                    {
                        x--;
                        d = 2;
                        k -= 2;
                        ans++;
                    }
                    if (d == 2)
                    {
                        x--;
                        k--;
                        ans++;
                    }
                    if (d == 3)
                    {
                        x--;
                        d = 2;
                        k -= 4;
                        ans++;
                    }
                }
            }
        }
        cout << ans;
    }
    return 0;
}
