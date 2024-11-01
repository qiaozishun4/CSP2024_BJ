#include <iostream>
#include <cstdio>
using namespace std;

char g[1005][1005];
bool vis[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k, x, y, d, ans = 0;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> g[i][j], vis[i][j] = false;
        vis[x][y] = true;
        while (k)
        {
            int tx = x + dx[d];
            int ty = y + dy[d];
            while (!(1 <= tx && tx <= n && 1 <= ty && ty <= m && g[tx][ty] == '.') && k)
                d = (d + 1) % 4, k--, tx = x + dx[d], ty = y + dy[d];
            if (k <= 0)
                break;
            x = tx, y = ty;
            vis[x][y] = true;
            k--;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (vis[i][j])
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
