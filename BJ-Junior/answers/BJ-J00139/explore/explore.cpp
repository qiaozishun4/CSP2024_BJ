#include <bits/stdc++.h>
#define ll long long
using namespace std;
int T, n, m, k, x, y, d, ans;
int dir[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char a[1005][1005];
bool vis[1005][1005];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        memset(vis, 0, sizeof(vis));
        ans = 1;
        vis[x][y] = 1;
        while (k--)
        {
            int nx = x + dir[d][0], ny = y + dir[d][1];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m && a[nx][ny] == '.')
            {
                x = nx;
                y = ny;
            }
            else
            {
                d = (d + 1) % 4;
            }
            if (!vis[x][y])
            {
                ans++;
            }
            vis[x][y] = 1;
        }
        cout << ans << endl;
    }
    return 0;
}

