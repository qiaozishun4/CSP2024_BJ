#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

bool vis[N][N];
char mp[N][N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        memset(mp, 0, sizeof mp);
        memset(vis, 0, sizeof vis);
        int n, m, k, x, y, d, tt = 1, nx, ny;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> mp[i][j];
        vis[x][y] = 1;
        for (int i = 1; i <= k; i++) {
            nx = x + dx[d], ny = y + dy[d];
            // cout <<x <<','<<y<<' '<<"d:"<<d<<'\n';
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] != 'x') {
                if (!vis[nx][ny])
                    tt++;
                vis[nx][ny] = 1;
                x = nx, y = ny;
            } else {
                d = (d + 1) % 4;
            }
        }
        cout << tt << '\n';
    }
    return 0;
}
