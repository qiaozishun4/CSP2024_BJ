#include <bits/stdc++.h>
using namespace std;
int t, n, m, k;
int ans = 1;
int sx, sy, sd;
int vis[1020][1020];
char a[1020][1020];
int dx[5]= {0, 1, 0, -1}, dy[5] = {1, 0, -1, 0};
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        cin >> sx >> sy >> sd;
        memset(vis, 0, sizeof(vis));
        ans = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        vis[sx][sy] = 1;
        int x = sx, y = sy, d = sd;
        while(k--)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.')
            {
                x = nx, y = ny;
                if(vis[nx][ny] == 0)
                {
                    vis[nx][ny] = 1;
                    ans++;
                  //cout << nx << " " << ny << endl;
                }

            }
            else d = (d + 1) % 4;
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}