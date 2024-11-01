

#include <iostream>

using namespace std;

const int MAXI = 1009;
int t;
int n, m, k;
int x, y, d;
char a[MAXI][MAXI];
bool vis[MAXI][MAXI];

int main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) cin >> a[i][j];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) vis[i][j] = 0;

        vis[x][y] = 1;
        while (k--) {
            int curX, curY;
            if (d == 0) curX = x, curY = y + 1;
            if (d == 1) curX = x + 1, curY = y;
            if (d == 2) curX = x, curY = y - 1;
            if (d == 3) curX = x - 1, curY = y;

            if (curX < 1 || curX > n) {
                d = (d + 1) % 4;
                continue;
            }
            if (curY < 1 || curY > m) {
                d = (d + 1) % 4;
                continue;
            }
            if (a[curX][curY] == 'x') {
                d = (d + 1) % 4;
                continue;
            }

            x = curX, y = curY;
            vis[x][y] = 1;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) ans += vis[i][j];
        cout << ans << '\n';
    }

    return 0;
}
