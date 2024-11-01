#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, sx, sy, sd;
char mp[1001][1001];
bool visited[1001][1001];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool inb(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}
void bfs(int sx, int sy, int sd) {
    visited[sx][sy] = true;
    int x = sx, y = sy, d = sd;
    for(int i = 1; i <= k; i++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(!inb(nx, ny) || mp[nx][ny] == 'x') {
            d = (d + 1) % 4;
            continue;
        }
        visited[nx][ny] = true;
        x = nx, y = ny;
    }
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while(t--) {
        memset(visited, 0, sizeof(visited));
        cin >> n >> m >> k >> sx >> sy >> sd;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) cin >> mp[i][j];
        }
        bfs(sx, sy, sd);
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) ans += visited[i][j];
        }
        cout << ans << endl;
    }
    return 0;
}