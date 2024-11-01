#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
struct Node {
    int x, y, d;
};
const Node mv[4] = {{0, 1, 0}, {1, 0, 0}, {0, -1, 0}, {-1, 0, 0}};

int t, n, m, k;
Node u;
char mp[maxn][maxn];

bool vis[maxn][maxn];
int ans;

bool canmove (Node v) {
    return 1 <= v.x && v.x <= n && 1 <= v.y && v.y <= m && mp[v.x][v.y] == '.';
}
int main () {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    scanf("%i", &t);
    while (t--) {
        memset(vis, false, sizeof(vis));
        ans = 0;

        scanf("%i%i%i", &n, &m, &k);
        scanf("%i%i%i", &u.x, &u.y, &u.d);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf(" %c", &mp[i][j]);
            }
        }

        vis[u.x][u.y] = true;
        ++k;
        while (--k) {
            Node v = {u.x + mv[u.d].x, u.y + mv[u.d].y, u.d};
            if (canmove(v)) {
                u = v;
            }else {
                u.d = (u.d + 1)%4;
            }
            vis[u.x][u.y] = true;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                ans += vis[i][j];
            }
        }

        printf("%i\n", ans);
    }
    return 0;
}