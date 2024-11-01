#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int T, k, n, m, ans = 0; // n*m
int dx[8] = {0, 1, 0, -1};
int dy[8] = {1, 0, -1, 0};
char map[1005][1005];
bool vis[1005][1005];
bool in(int xx, int yy) {
    return xx < n && xx >= 0 && yy < m && yy >= 0;
}
int dfs (int cnt, int x, int y, int d, int k) {
    vis[x][y] =1;
    if (k == 0) {
        return cnt;
    }
    int tx = x + dx[d];
    int ty = y + dy[d];

    if (in(tx, ty) && map[tx][ty] != '#') {
        if (vis[tx][ty] == 0) {
            cnt++;
            vis[tx][ty] = 1;
        }
        //cout << cnt << " - weizhi:" << tx << ty  << " dir:" << d << " last:" << k << endl;
        dfs(cnt, tx, ty, d, k-1);
    } else {

        //cout << cnt << " - weizhi:" << tx << ty  << " dir:" << d << " last:" << k << endl;
        dfs(cnt, x, y, (d + 1) % 4, k-1);
    }

}
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    scanf("%d", &T);
    // T datas
    while (T--) {
        memset(map, 0, sizeof(map));
        memset(vis, 0, sizeof(vis));

        scanf("%d%d%d", &n, &m, &k); // 1-cin
        int x, y, d;
        scanf("%d%d%d", &x, &y, &d); // 2-cin
        x--; y--;
        for (int i = 0; i < n; i++) { // 3-cin
            scanf("%s", &map[i]);
        }

        ans = dfs(1, x, y, d, k);
        printf("%d\n", ans);
    }
    return 0;
}
