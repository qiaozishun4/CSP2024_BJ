#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int t, n, m;
char a[1010][1010];

bool check(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || a[x][y] == 'x') return true;
    return false;
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        int k, x, y, d, ans = 0;
        bool vis[1010][1010];
        memset(vis, false, sizeof(vis));
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        vis[x][y] = true;
        for (int i = 1; i <= k; i++)
        {
            if (d == 0)
            {
                if (check(x, y + 1))
                    d = (d + 1) % 4;
                else
                {
                    y++;
                    vis[x][y] = true;
                }
            }
            else if (d == 1)
            {
                if (check(x + 1, y))
                    d = (d + 1) % 4;
                else
                {
                    x++;
                    vis[x][y] = true;
                }
            }
            else if (d == 2)
            {
                if (check(x, y - 1))
                    d = (d + 1) % 4;
                else
                {
                    y--;
                    vis[x][y] = true;
                }
            }
            else if (d == 3)
            {
                if (check(x - 1, y))
                    d = (d + 1) % 4;
                else
                {
                    x--;
                    vis[x][y] = true;
                }
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (vis[i][j])
                    ans++;
        cout << ans << endl;
    }
    return 0;
}
