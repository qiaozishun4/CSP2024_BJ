#include <bits/stdc++.h>
using namespace std;
int T, n, m, k, x, y, d, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char mp[1024][1024];
bool vis[1024][1024];
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> mp[i][j];
        memset(vis, false, sizeof vis);
        vis[x][y] = true;
        queue<int> qx, qy;
        qx.push(x), qy.push(y);
        while (k--) {
            int nx = qx.front() + dx[d], ny = qy.front() + dy[d];
            //cout << nx << " " << ny << endl;
            if (nx < 1 || nx > n || ny < 1 || ny > m || mp[nx][ny] == 'x') d = (d + 1) % 4;
            else {
                qx.pop();
                qy.pop();
                qx.push(nx);
                qy.push(ny);
                vis[nx][ny] = true;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
               if (vis[i][j])
                    ans++;
        cout << ans << endl;
    }
    return 0;
}
