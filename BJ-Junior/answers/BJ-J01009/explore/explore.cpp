#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int T;
int n, m, k;
int x, y, d;
int vis[maxn][maxn], mp[maxn][maxn];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool ok(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] == 1;
}
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        memset(mp, 0, sizeof(mp));
        memset(vis, 0, sizeof(vis));
        scanf("%d%d%d", &n, &m, &k);
        scanf("%d%d%d", &x, &y, &d);
        for (int i = 1; i <= n; i++) {
            getchar();
            for (int j = 1; j <= m; j++) {
                char p;
                scanf("%c", &p);
                if (p == '.') {
                    mp[i][j] = 1;
                } else {
                    mp[i][j] = 0;
                }
            }
        }
        vis[x][y] = 1;
        while (k--) {
            if (ok(x + dx[d], y + dy[d])) {
                x += dx[d];
                y += dy[d];
            } else {
                d = (d + 1) % 4;
            }
            vis[x][y] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ans += vis[i][j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
