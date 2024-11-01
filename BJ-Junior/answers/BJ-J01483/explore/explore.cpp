#include <iostream>
using namespace std;

int T, n, m, k, sx, sy, d, cnt = 0;
bool vis[1005][1005];
int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};
char g[1005][1005];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore,out", "w", stdout);
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> k;
        cin >> sx >> sy >> d;
        vis[sx][sy] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> g[i][j];
            }
        }
        for(int i = 1; i <= k; i++)
        {
            int nx = sx + dx[d], ny = sy + dy[d];
            if(nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] == 'x')
            {
                d = (d + 1) % 4;
                continue;
            }
            sx = nx, sy = ny, vis[nx][ny] = 1;
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(vis[i][j] == 1) cnt++;
            }
        }
        cout << cnt << endl;
        cnt = 0;
    }
    return 0;
}
