#include <bits/stdc++.h>

using i64 = long long;
auto& IG = std::ignore;

//#define debug(s, ...) fprintf(stderr, s, ##__VA_ARGS__), fflush(stderr)

const i64 MAXN = 1010;
i64 dx[] = {0, 1, 0, -1};
i64 dy[] = {1, 0, -1, 0};
char gr[MAXN][MAXN];
i64 n, m, k, vis[MAXN][MAXN];

void solve(void){
    memset(vis, 0, sizeof(vis));
    IG = scanf("%lld%lld%lld", &n, &m, &k);
    i64 x = 0, y = 0, d = 0;
    IG = scanf("%lld%lld%lld", &x, &y, &d);
    for (i64 i = 1; i <= n; ++i) {
        IG = scanf("%s", gr[i] + 1);
    }
    while (k--) {
        vis[x][y] = 1;
        i64 nx = x + dx[d], ny = y + dy[d];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && gr[nx][ny] == '.') {
            x = nx, y = ny;
        }
        else {
            d = (d + 1) % 4;
        }
        vis[x][y] = 1;
    }
    i64 ans = 0;
    for (i64 i = 1; i <= n; ++i) {
        for (i64 j = 1; j <= m; ++j) {
            ans += vis[i][j];
        }
    }
    printf("%lld\n", ans);
}

int main() {
    IG = freopen("explore.in", "r", stdin);
    IG = freopen("explore.out", "w", stdout);

    i64 t = 0;
    IG = scanf("%lld", &t);
    while (t--) solve();

    return 0;
}
