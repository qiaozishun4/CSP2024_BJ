#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LL __int128

const int N = 1e3 + 5;
int n, m, K, T, vis[N][N], sx, sy, sd;
char a[N][N];
int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool check(int x, int y) {
    if(x > n || x < 1 || y > m || y < 1) return false;
    if(a[x][y] == 'x') return false;
    return true;
}

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    scanf("%d", &T);
    while(T--) {
        memset(vis, 0, sizeof vis);
        scanf("%d%d%d", &n, &m, &K);
        scanf("%d%d%d", &sx, &sy, &sd);
        for(int i = 1; i <= n; i++) scanf("%s", a[i]+1);

        vis[sx][sy] = true;
        for(int i = 1; i <= K; i++) {
            int x = sx + d[sd][0], y = sy + d[sd][1];
            if(!check(x, y)) {
                sd = (sd+1) % 4;
                continue;
            }
            sx = x;  sy = y;
            vis[sx][sy] = true;
        }

        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) ans += vis[i][j];

        printf("%d\n", ans);
    }
    return 0;
}
