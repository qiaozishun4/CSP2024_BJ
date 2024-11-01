/*
Glory Glory Man United
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 100;
char a[N][N];
int vis[N][N];

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, k;
        int x, y, d;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; i++)
            for  (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                vis[i][j] = 0;
            }
        int dnow = d, nx = x, ny = y, ans = 1;
        vis[x][y] = 1;
        for (int i = 1; i <= k; i++)
        {
            if (dnow == 1)
            {
                if (a[nx + 1][ny] == '.' && nx + 1 <= n && nx + 1 >= 1 && ny <= m && ny >= 1)
                {
                    nx = nx + 1;
                    if (vis[nx][ny] == 0) ans++;
                    vis[nx][ny] = 1;
                }
                else dnow = (dnow + 1) % 4;
            }
            else if (dnow == 0)
            {
                if (a[nx][ny + 1] == '.' && nx <= n && nx >= 1 && ny + 1 <= m && ny + 1 >= 1)
                {
                    ny = ny + 1;
                    if (vis[nx][ny] == 0) ans++;
                    vis[nx][ny] = 1;
                }
                else dnow = (dnow + 1) % 4;
            }
            else if (dnow == 3)
            {
                if (a[nx - 1][ny] == '.' && nx - 1 <= n && nx - 1 >= 1 && ny <= m && ny >= 1)
                {
                    nx = nx - 1;
                    if (vis[nx][ny] == 0) ans++;
                    vis[nx][ny] = 1;
                }
                else dnow = (dnow + 1) % 4;
            }
            else if (dnow == 2)
            {
                if (a[nx][ny - 1] == '.' && nx <= n && nx >= 1 && ny - 1 <= m && ny - 1 >= 1)
                {
                    ny = ny - 1;
                    if (vis[nx][ny] == 0) ans++;
                    vis[nx][ny] = 1;
                }
                else dnow = (dnow + 1) % 4;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
