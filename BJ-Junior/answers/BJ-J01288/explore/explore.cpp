#include <bits/stdc++.h>
using namespace std;

char c[1010][1010];
bool vis[1010][1010];

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        memset(vis, 0, sizeof vis);
        int n, m, k;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cin >> c[i][j];
        int nx, ny;
        vis[x][y] = 1;
        while (k--) {
            switch(d) {
                case 0 : nx = x, ny = y + 1; break;
                case 1 : nx = x + 1, ny = y; break;
                case 2 : nx = x, ny = y - 1; break;
                case 3 : nx = x - 1, ny = y; break;
            }
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m && c[nx][ny] == '.') {
                vis[nx][ny] = 1;
                x = nx, y = ny;
            }
            else d = (d + 1) % 4;
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                ans += vis[i][j];
        cout << ans << endl;
    }
    return 0;
}