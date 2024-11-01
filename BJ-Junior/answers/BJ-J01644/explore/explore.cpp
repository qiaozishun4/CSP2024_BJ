#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, y, d;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char mp[1005][1005];
bool vis[1005][1005];
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m >> k >> x >> y >> d;
        memset(mp, 0, sizeof(mp));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; ++i)
            cin >> mp[i] + 1;
        vis[x][y] = 1;
        while (k--) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 1 || nx > n || ny < 1 || ny > m || mp[nx][ny] == 'x') d = (d + 1) % 4;
            else {x = nx; y = ny;}
            vis[x][y] = true;
        } int cnt = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) cnt += vis[i][j];
        cout << cnt << endl;
    }
    return 0;
}
