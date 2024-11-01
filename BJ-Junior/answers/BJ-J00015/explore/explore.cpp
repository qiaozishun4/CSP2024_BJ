#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e3 + 5;

int n, m, k;
int cnt = 0, ans = 0;
int vis[MAXN][MAXN];
int dir[5][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int g[MAXN][MAXN];
bool flag = false;

void dfs(int x, int y, int leftmv, int d) {
    if (leftmv <= 0) {
        ans = cnt;
        flag = true;
        return ;
    }
    if (flag == true) return ;

    int nx = x + dir[d][0];
    int ny = y + dir[d][1];
    if (g[nx][ny] == 1) {
        if (vis[nx][ny] == 0) cnt++;

        vis[nx][ny] = 1;
        ans = max(ans, cnt);
        dfs(nx, ny, leftmv - 1, d);
    } else {
        if (leftmv <= 1) {
            ans = cnt;
            flag = true;
            return ;
        }
        while (leftmv > 1) {
            leftmv--;
            d = (d + 1) % 4;

            int nx = x + dir[d][0];
            int ny = y + dir[d][1];
            if (g[nx][ny] == 1) {
                if (vis[nx][ny] == 0) cnt++;

                vis[nx][ny] = 1;
                ans = max(ans, cnt);
                dfs(nx, ny, leftmv - 1, d);
            }
            if (flag == true) return ;
        }

    }
}

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    int T;
    cin >> T;

    while (T--) {
        cin >> n >> m >> k;
        int sx, sy, d0;
        cin >> sx >> sy >> d0;

        for (int i = 0; i <= 1001; i++) {
            for (int j = 0; j <= 1001; j++) {
                g[i][j] = 0;
                vis[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char c;
                cin >> c;

                if (c == '.') g[i][j] = 1;
            }
        }

        flag = false;
        cnt = 1, ans = 1;
        vis[sx][sy] = 1;
        dfs(sx, sy, k, d0);
        cout << cnt << "\n";
    }

    return 0;
}
