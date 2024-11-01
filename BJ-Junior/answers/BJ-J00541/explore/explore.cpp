#include <iostream>

using namespace std;

int t, n, m, k, x0, y0, d0;
const int N = 1e3;
char g[N + 1][N + 1];
bool vis[N + 1][N + 1];
int ans;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void f() {
    int x = x0, y = y0, d = d0;
    vis[x][y] = 1;
    ans ++;
    while(k --) {
        int nx = x + dx[d], ny = y + dy[d];
        if(1 <= nx && nx <= n && 1 <= ny && ny <= m && g[nx][ny] == '.') {
            if(vis[nx][ny] == 0) ans ++;
            vis[nx][ny] = 1;
            x = nx, y = ny;
        }
        else {
            d = (d + 1) % 4;
        }
    }
}

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    cin >> t;
    while(t --) {
        cin >> n >> m >> k;
        cin >> x0 >> y0 >> d0;
        ans = 0;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                cin >> g[i][j];
                vis[i][j] = 0;
            }
        }
        f();
        cout << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
