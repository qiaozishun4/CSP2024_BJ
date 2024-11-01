#include <bits/stdc++.h>
using namespace std;

char a[2005][2005];
bool vis[2005][2005];

int dfs(int x, int y, int d, int cnt, int k, int step, int n, int m) {
    if (step == k) return cnt;
    vis[x][y] = 1;
    if (d == 0) {
        if (y + 1 <= m && y + 1 >= 1 && a[x][y + 1] != 'x') {
            if (vis[x][y+1]) dfs(x, y + 1, d, cnt, k, step + 1, n, m);
            else {
                vis[x][y+1] = 1;
                dfs(x, y + 1, d, cnt + 1, k, step + 1, n, m);
            }
        } else dfs(x, y, (d + 1) % 4, cnt, k, step + 1, n, m);
    } else if (d == 1) {
        if (x + 1 <= n && x + 1 >= 1 && a[x + 1][y] != 'x') {
            if (vis[x+1][y]) dfs(x + 1, y, d, cnt, k, step + 1, n, m);
            else {
                vis[x+1][y] = 1;
                dfs(x + 1, y, d, cnt + 1, k, step + 1, n, m);
            }
        } else dfs(x, y, (d + 1) % 4, cnt, k, step + 1, n, m);
    } else if (d == 2) {
        if (y - 1 <= m && y - 1 >= 1 && a[x][y - 1] != 'x') {
            if (vis[x][y-1]) dfs(x, y - 1, d, cnt, k, step + 1, n, m);
            else {
                vis[x][y-1] = 1;
                dfs(x, y - 1, d, cnt + 1, k, step + 1, n, m);
            }
        } else dfs(x, y, (d + 1) % 4, cnt, k, step + 1, n, m);
    } else if (d == 3) {
        if (x - 1 <= n && x - 1 >= 1 && a[x - 1][y] != 'x') {
            if (vis[x-1][y]) dfs(x - 1, y, d, cnt, k, step + 1, n, m);
            else {
                vis[x-1][y] = 1;
                dfs(x - 1, y, d, cnt + 1, k, step + 1, n, m);
            }
        } else dfs(x, y, (d + 1) % 4, cnt, k, step + 1, n, m);
    }
}

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T; cin >> T;
    while (T--) {
        memset(a, 0, sizeof a);
        memset(vis, 0, sizeof vis);
        int n, m, k, x0, y0, d0;
        cin >> n >> m >> k >> x0 >> y0 >> d0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        cout << dfs(x0, y0, d0, 1, k, 0, n, m) << "\n";
    }
    return 0;
}
