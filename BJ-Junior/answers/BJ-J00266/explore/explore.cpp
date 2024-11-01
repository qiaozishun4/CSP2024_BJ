#include <cstdio>

int T, n, m, k, x, y, d, xx, yy, ans;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char a[1001][1001];

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    for (scanf("%d", &T); T--; ) {
        ans = 1;
        scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &d);
        for (int i = 1; i <= n; ++i)
            scanf("%s", a[i] + 1);
        a[x][y] = '-';
        while (k--) {
            xx = x + dx[d];
            yy = y + dy[d];
            if (xx <= 0 or xx > n or yy <= 0 or yy > m or a[xx][yy] == 'x')
                d = d + 1 & 3;
            else {
                x = xx;
                y = yy;
            }
            ans += (a[x][y] == '.');
            a[x][y] = '-';
        }
        printf("%d\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
