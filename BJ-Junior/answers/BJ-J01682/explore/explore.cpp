#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char a[1005][1005];
bool vis[1005][1005];
int n, m, k, x, y, d;
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &d);
        for (int i = 1; i <= n; i++)
            scanf("%s", a[i] + 1);
        memset(vis, 0, sizeof(vis));
        vis[x][y] = 1;
        while(k--)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 1 ||nx > n || ny < 1 || ny > m || a[nx][ny] != '.')
            {
                d = (d + 1) % 4;
                continue;
            }
            vis[nx][ny] = 1;
            x = nx;
            y = ny;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (vis[i][j]) cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}
