#include <iostream>
#include <cstring>
using namespace std;

int t, n, m, k, x, y, d;
char a[1005][1005];
bool vis[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        memset(vis, false, sizeof vis);
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cin >> a[i][j];
        int ans = 1;
        vis[x][y] = true;
        while (k--)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == 'x') d = (d + 1) % 4;
            else
            {
                x = nx, y = ny;
                if (!vis[x][y]) ++ans;
                vis[x][y] = true;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
