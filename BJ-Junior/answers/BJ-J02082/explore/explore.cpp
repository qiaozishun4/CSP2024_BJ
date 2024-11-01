#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int N = 1e3 + 10;
bool g[N][N], ans[N][N];

signed main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        memset(ans, 0, sizeof(ans));
        int n, m, k, x0, y0, d0;
        cin >> n >> m >> k >> x0 >> y0 >> d0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                char x;
                cin >> x;
                if (x == 'x') g[i][j] = 1;
                else g[i][j] = 0;
            }
        }
        int x = x0, y = y0, d = d0;
        ans[x][y] = true;
        for (int i = 1; i <= k; ++i) {
            if (d == 0) {
                if (g[x][y + 1] || y == m) d = (d + 1) % 4;
                else ans[x][++y] = true;
            }
            else if (d == 1) {
                if (g[x + 1][y] || x == n) d = (d + 1) % 4;
                else ans[++x][y] = true;
            }
            else if (d == 2) {
                if (g[x][y - 1] || y == 1) d = (d + 1) % 4;
                else ans[x][--y] = true;
            }
            else if (d == 3) {
                if (g[x - 1][y] || x == 1) d = (d + 1) % 4;
                else ans[--x][y] = true;
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cnt += ans[i][j];
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
