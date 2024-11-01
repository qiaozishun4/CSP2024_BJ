#include <bits/stdc++.h>
using namespace std;

int fx[4] = {0, 1, 0, -1}, fy[4] = {1, 0, -1, 0}, vis[1005][1005];
char a[1005][1005];

//(x, y + 1)
//(x + 1, y)
//(x, y − 1)
//(x − 1, y)

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cin >> a[i][j];
            }
        }
        vis[x][y] = 1;
        for (int i = 1; i <= k; ++i)
        {
            int nx = x + fx[d], ny = y + fy[d];
            if (nx < 1 || nx > n || ny < 1 || ny > m)
            {
                d = (d + 1) % 4;
                continue;
            }
            if (a[nx][ny] == 'x')
            {
                d = (d + 1) % 4;
                continue;
            }
            x = nx, y = ny;
            vis[x][y] = 1;
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j) if (vis[i][j]) ++cnt;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j) vis[i][j] = 0;
        }
        cout << cnt << endl;
    }
    return 0;
}
