#include<bits/stdc++.h>
using namespace std;
bool b[1005][1005];
char c[1005][1005];
int t, n, m, k;
int o[10][5] = {{0, 1, 0, -1}, {1, 0, -1, 0}};
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    scanf("%d", &t);
    while(t--) {
        o[2][1] = -1, o[3][0] = -1;
        int x, y, d, cnt = 1;
        scanf("%d%d%d", &n, &m, &k);
        scanf("%d%d%d", &x, &y, &d);
        b[x][y] = true;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf(" %c ", &c[i][j]);
        while (k--) {
            int dx = x + o[d][0], dy = y + o[d][1];
            if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && c[dx][dy] == '.') {
                x = dx, y = dy;
                if (!b[x][y]) {
                    cnt++;
                    b[x][y] = true;
                }
            } else d = (d + 1) % 4;
        }
        printf("%d\n", cnt);
        memset(b, 0, sizeof(b));
    }
    return 0;
}