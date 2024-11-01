#include <bits/stdc++.h>
using namespace std;

char a[1005][1005];
int vis[1005][1005];
int wx[4] = {0, 1, 0, -1};
int wy[4] = {1, 0, -1, 0};
int n, m;
bool in(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T, k;
    cin >> T;
    while(T--) {
        cin >> n >> m >> k;
        ++k;
        int x0, y0, d0;
        cin >> x0 >> y0 >> d0;
        for (int i = 0; i <= n + 1; ++i) for (int j = 0; j <= m + 1; ++j) a[i][j] = 'x', vis[i][j] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> a[i][j];
            }
        }
        int ans = 0;
        while(k--) {
            if(vis[x0][y0] != 1) ++ans;
            vis[x0][y0] = 1;
            int dx = x0 + wx[d0];
            int dy = y0 + wy[d0];
            if(!in(dx, dy) || a[dx][dy] == 'x') {
                d0 = (d0 + 1) % 4;
            } else {
                x0 = dx;
                y0 = dy;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
