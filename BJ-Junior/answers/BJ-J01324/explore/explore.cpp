#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e3 + 10;
int t, n, m, k, x0, y0, d0;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char c[N][N];
bool vis[N][N];
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while (t--) {
        memset(vis, 0, sizeof(vis));
        cin >> n >> m >> k >> x0 >> y0 >> d0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cin >> c[i][j];
        int x = x0, y = y0, d = d0;
        vis[x0][y0] = 1;
        while (k--) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && c[nx][ny] != 'x') {
                vis[nx][ny] = 1;
                x = nx, y = ny;
            }
            else d = (d + 1) % 4;
            // printf("x:%d, y:%d, d:%d, vis(x, y):%d\n", x, y, d, vis[x][y]);
        }
        int res = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (vis[i][j]) res++;
        cout << res << endl;
    }
    return 0;
}
