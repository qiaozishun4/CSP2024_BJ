#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int t;
int n, m, k;
int x0, y0, d0;
int ans;
string mapp[1005];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool vis[1005][1005];
void robot_move(int &x, int &y, int &d) {
    int nx = x + dir[d][0];
    int ny = y + dir[d][1];

    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
        d = (d + 1) % 4;
        return;
    }

    if (mapp[nx][ny] == 'x') {
        d = (d + 1) % 4;
        return;
    }

    if (!vis[nx][ny]) {
        vis[nx][ny] = true;
        ans++;
    }

    x = nx, y = ny;
}
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    memset(vis, false, sizeof(vis));
    while (t--) {
        cin >> n >> m >> k;
        cin >> x0 >> y0 >> d0;
        x0--, y0--;
        for (int i = 0; i < n; i++) {
            cin >> mapp[i];
        }
        vis[x0][y0] = true;
        ans = 1;
        while (k--) {
            robot_move(x0, y0, d0);
        }

        cout << ans << endl;
        memset(vis, false, sizeof(vis));
    }
    return 0;
}
