#include <bits/stdc++.h>
using namespace std;

int n, m, k, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool vis[1010][1010];
char grid[1010][1010];
void work() {
    memset(vis, 0, sizeof vis);
    int x, y, d;
    cin >> n >> m >> k >> x >> y >> d;
    vis[x][y] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= k; i++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 1 || nx > n || ny < 1 || ny > m || grid[nx][ny] == 'x') {
            d = (d + 1) % 4;
            continue;
        }
        vis[nx][ny] = 1, x = nx, y = ny;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += vis[i][j];
        }
    }
    cout << ans << '\n';
}
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}
