#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int n, m, k, sx, sy, sd;
string g[maxn];
bool vis[maxn][maxn];
bool inb(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
int solve() {
    memset(vis, 0, sizeof(vis));
    int x = sx - 1, y = sy - 1, d = sd;
    vis[x][y] = true;
    while (k--) {
        int nx = x + dx[d], ny = y + dy[d];
        if (inb(nx, ny) && g[nx][ny] == '.') {
            x = nx;
            y = ny;
        } else d = (d + 1) % 4;
        vis[x][y] = true;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (vis[i][j])
                cnt++;
    return cnt;
}
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m >> k >> sx >> sy >> sd;
        for (int i = 0; i < n; i++) cin >> g[i];
        cout << solve() << "\n";
    }
    return 0;
}

