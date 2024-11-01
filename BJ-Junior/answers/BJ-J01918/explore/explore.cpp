#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1e3 + 8;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int n, m, k, x, y, d, nx, ny, nd, ans;
int grid[MAXN][MAXN];
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        memset(grid, -1, sizeof(grid));
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                char ch;
                cin >> ch;
                if (ch == '.') grid[i][j] = 1;
            }
        ans = 1;
        grid[x][y] = 0;
        while (k--) {
            nx = x + dx[d], ny = y + dy[d];
            if (grid[nx][ny] < 0)
                d = (d + 1) % 4;
            else {
                ans += grid[nx][ny];
                grid[nx][ny] = 0;
                x = nx;
                y = ny;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
