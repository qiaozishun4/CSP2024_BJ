#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, y, d, dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, ans;
int vis[1010][1010];
string a[1010];
void dfs(int sx, int sy, int sd)
{
    vis[sx][sy] = 1;
    while (k--)
    {
        int tx = sx + dir[sd][0];
        int ty = sy + dir[sd][1];
        if (tx >= n || tx < 0 || ty >= m || ty < 0 || a[tx][ty] == 'x')
        {
            sd = (sd + 1) % 4;
            continue;
        }
        sx = tx;
        sy = ty;
        vis[sx][sy] = 1;
    }
}
int main ()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        ans = 0;
        memset(vis, 0, sizeof(vis));
        cin >> n >> m >> k >> x >> y >> d;
        x--;
        y--;
        for (int i = 0; i < n; i++) cin >> a[i];
        dfs(x, y, d);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j]) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
