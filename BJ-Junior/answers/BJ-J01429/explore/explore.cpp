#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int T, n, m, k, x0, y_0, d0, cnt, nx, ny;
char mp[1005][1005];
bool vis[1005][1005];

void dfs(int x, int y, int d, int step) {
    if (step > k) return;
    if (d == 0) {
        nx = x;
        ny = y + 1;
    }
    if (d == 1) {
        nx = x + 1;
        ny = y;
    }
    if (d == 2) {
        nx = x;
        ny = y - 1;
    }
    if (d == 3) {
        nx = x - 1;
        ny = y;
    }
    //cout << "nx,ny:" << nx << " " << ny << endl;
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] == '.') {
        if (!vis[nx][ny]) cnt++;
        vis[nx][ny] = 1;
        dfs(nx, ny, d, step + 1);
    }
    else {
        dfs(x, y, (d + 1) % 4, step + 1);
    }
}

void solve() {
    memset(mp, 0, sizeof mp);
    memset(vis, 0, sizeof vis);
    cin >> n >> m >> k;
    cin >> x0 >> y_0 >> d0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    cnt = 1;
    vis[x0][y_0] = 1;
    dfs(x0, y_0, d0, 1);
    cout << cnt << "\n";
}

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    cin >> T;
    while (T--) solve();

    return 0;
}
