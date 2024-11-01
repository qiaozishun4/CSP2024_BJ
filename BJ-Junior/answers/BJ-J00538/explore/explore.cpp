#include <bits/stdc++.h>
using namespace std;
int T, n, m, k, x, y, d;
char mp[1005][1005];
bool vis[1005][1005];
int cnt = 0;
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &d);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("\n%c", &mp[i][j]);
        memset(vis, 0, sizeof(vis));
        vis[x][y] = 1;
        while (k--)
        {
            int nxtx = x, nxty = y;
            switch (d)
            {
                case 0: nxty++; break;
                case 1: nxtx++; break;
                case 2: nxty--; break;
                case 3: nxtx--; break;
            }
            if (nxtx < 1 || nxtx > n || nxty < 1 || nxty > m || mp[nxtx][nxty] == 'x')
                d = (d + 1) % 4;
            else
                x = nxtx, y = nxty;
            vis[x][y] = 1;
        }
        cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cnt += vis[i][j];
        printf("%d\n", cnt);
    }
    return 0;
}
