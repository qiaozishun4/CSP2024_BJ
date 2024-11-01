#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll dx[5] = {0, 1, 0, -1};
const ll dy[5] = {1, 0, -1, 0};
ll T, n, m, k, xx, yy, dd;
char mp[1005][1005];
bool vis[1005][1005];
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while (T--) {
        memset(vis, false, sizeof(vis));
        cin >> n >> m >> k >> xx >> yy >> dd;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> mp[i][j];
            }
        }
        ll x = xx, y = yy, dir = dd;
        vis[x][y] = true;
        for (int i = 1; i <= k; i++) {
            ll nx = x + dx[dir];
            ll ny = y + dy[dir];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] != 'x') {
                x = nx, y = ny;
                vis[nx][ny] = true;
            } else {
                dir = (dir + 1) % 4;
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (vis[i][j] == true) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
