#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 1e3 + 5;

char a[N][N];
bool vis[N][N];

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    for (int tst = 1; tst <= T; tst++)
    {
        memset(vis, false, sizeof vis);
        int n, m, k, x, y, d;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        int ans = 1;
        vis[x][y] = true;
        for (int i = 1; i <= k; i++)
        {
            if (d == 0)
            {
                if (y + 1 <= m && a[x][y + 1] == '.') y++;
                else d = (d + 1) % 4;
            }
            else if (d == 1)
            {
                if (x + 1 <= n && a[x + 1][y] == '.') x++;
                else d = (d + 1) % 4;
            }
            else if (d == 2)
            {
                if (y - 1 >= 1 && a[x][y - 1] == '.') y--;
                else d = (d + 1) % 4;
            }
            else
            {
                if (x - 1 >= 1 && a[x - 1][y] == '.') x--;
                else d = (d + 1) % 4;
            }
            if (!vis[x][y])
            {
                ans++;
                vis[x][y] = true;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
