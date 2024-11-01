#include <cstdio>
#include <iostream>
using namespace std;
int t, n, m, k, x, y, d;
char mp[1010][1010];
bool visit[1010][1010];
int dx[5] = {1, 0, -1, 0}, dy[5] = {0, 1, 0, -1};
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    scanf("%d", &t);
    for (int i = 0; i < t; ++ i) {
        scanf("%d %d %d\n%d %d %d", &n, &m, &k, &x, &y, &d);
        for (int row = 1; row <= n; ++ row)
            for (int col = 1; col <= m; ++ col)
                cin >> mp[row][col];
        int ex, ey, cnt = 1;
        visit[x][y] = true;
        for (int j = 1; j <= k; ++ j) {
            x += dx[d];
            y += dy[d];
            if (1 <= x && x <= m && 1 <= y && y <= n && mp[y][x] != 'x') {
                if (!visit[y][x]) {
                    visit[y][x] = true;
                    ++ cnt;
                }
            }
            else {
                x -= dx[d];
                y -= dy[d];
                d = (d + 1) % 4;
            }
        }
        for (int row = 1; row <= n; ++ row)
            for (int col = 1; col <= m; ++ col)
                visit[row][col] = 0;
        printf("%d\n", cnt);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
