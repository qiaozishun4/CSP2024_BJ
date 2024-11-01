#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n, m, k, x, y, d;
char mp[N][N];
bool vis[N][N];
bool inb(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--) {
        memset(mp, 0, sizeof(mp));
        memset(vis, 0, sizeof(vis));
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> mp[i][j];
            }
        }
        vis[x][y] = 1;
        for (int i = 1; i <= k; i++) {
            int tx = x + dx[d], ty = y + dy[d];
            if (inb(tx, ty) && mp[tx][ty] == '.') x = tx, y = ty;
            else d = (d + 1) % 4;
            vis[x][y] = 1;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (vis[i][j]) cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
