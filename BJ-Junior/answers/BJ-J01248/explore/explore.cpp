#include <bits/stdc++.h>
using namespace std;

char a[1005][1005];
int vis[1005][1005];
int T, n, m, k, x, y, d;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        int cnt = 1;
        memset(vis, 0, sizeof vis);
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        vis[x][y] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i = 1; i <= k; i++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == 'x')
            {
                d += 1;
                d %= 4;
                continue;
            }
            x = nx, y = ny;
            if(vis[x][y] == 0)
                cnt++;
            vis[x][y] = 1;
        }
        cout << cnt << endl;
    }
    return (0);
}
