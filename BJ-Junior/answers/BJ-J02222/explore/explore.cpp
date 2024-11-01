#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char maps[1007][1007];
bool vis[1007][1007];
int T, n, m, k, xz, yz, dz, ans;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    while (T--)
    {
        memset(vis, 0, sizeof(vis));
        cin >> n >> m >> k >> xz >> yz >> dz;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> maps[i][j];
        ans = 1;
        int x = xz, y = yz, d = dz;
        vis[x][y] = 1;
        while (k--)
        {
            int tx = x + dx[d];
            int ty = y + dy[d];
            if (maps[tx][ty] == '.' && 1 <= tx && tx <= n && 1 <= ty && ty <= m)
            {
                x = tx;
                y = ty;
                if (vis[x][y] == 0)
                {
                    vis[x][y] = 1;
                    ans++;
                }
            }
            else
                d = (d + 1) % 4;
        }
        cout << ans << endl;
    }
    return 0;
}
