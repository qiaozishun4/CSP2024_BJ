#include <bits/stdc++.h>
using namespace std;
char c[1005][1005];
int vis[1005][1005];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k, x, y, d, ans = 0;
        cin >> n >> m >> k >> x >> y >> d;
        int nx = x, ny = y;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++) cin >> c[i][j];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++) vis[i][j] = 0;
        }
        vis[x][y] = 1;
        while (k--)
        {
            if (d == 0)
            {
                if (ny + 1 > m || c[nx][ny + 1] == 'x')
                {
                    d = (d + 1) % 4;
                    continue;
                }
                else
                {
                    ny++;
                    vis[nx][ny] = 1;
                }
            }
            if (d == 1)
            {
                if (nx + 1 > n || c[nx + 1][ny] == 'x')
                {
                    d = (d + 1) % 4;
                    continue;
                }
                else
                {
                    nx++;
                    vis[nx][ny] = 1;
                }
            }
            if (d == 2)
            {
                if (ny - 1 < 1 || c[nx][ny - 1] == 'x')
                {
                    d = (d + 1) % 4;
                    continue;
                }
                else
                {
                    ny--;
                    vis[nx][ny] = 1;
                }
            }
            if (d == 3)
            {
                if (nx - 1 < 1 || c[nx - 1][ny] == 'x')
                {
                    d = (d + 1) % 4;
                    continue;
                }
                else
                {
                    nx--;
                    vis[nx][ny] = 1;
                }
            }
            //cout << nx << " " << ny << " " << d << endl;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (vis[i][j]) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}