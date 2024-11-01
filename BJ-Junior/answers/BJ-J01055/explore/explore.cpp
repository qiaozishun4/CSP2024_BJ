#include <cstring>
#include <iostream>
using namespace std;

int x, y, d, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, cnt = 1, vis[1010][1010];
char g[1010][1010];

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        memset(vis, 0, sizeof vis);
        int n, m, k;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1;i <= n; i++)
            for(int j = 1;j <= m; j++)
                cin >> g[i][j];
        cnt = 1;
        for(int i = 1;i <= k; i++)
        {
            vis[x][y] = 1;
            int nx = x + dx[d], ny = y + dy[d];
            if(g[nx][ny] == '.' && nx >= 1 && nx <= n && ny >= 1 && ny <= m)
            {
                if(!vis[nx][ny]) cnt++;
                x = nx;
                y = ny;
            }
            else d = (d + 1) % 4;
        }
        cout << cnt << endl;
    }
    return 0;
}
