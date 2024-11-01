#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int walk[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool flag[1001][1001], vis[1001][1001];
void solve()
{
    int n, m, k, x, y, d;
    cin >> n >> m >> k >> x >> y >> d;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '.')
            {
                flag[i][j] = 1;
            }
            else if (ch == 'x')
            {
                flag[i][j] = 0;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    vis[x][y] = 1;
    for (int i = 1; i <= k; i++)
    {
        int tx = x + walk[d][0], ty = y + walk[d][1];
        if (flag[tx][ty] && tx >= 1 && tx <= n && ty >= 1 && ty <= m)
        {
            x = tx;
            y = ty;
        }
        else
        {
            d = (d + 1) % 4;
        }
        vis[x][y] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (vis[i][j])
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
