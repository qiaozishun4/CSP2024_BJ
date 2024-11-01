#include <bits/stdc++.h>
using namespace std;

int T;
int dir[5][5] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char s[1005][1005];

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    cin >> T;

    while (T--) {
        int n, m, k, x, y, d, ans = 0;

        cin >> n >> m >> k;
        cin >> x >> y >> d;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> s[i][j];
            }
        }

        ans++;
        s[x][y] = '0';

        while (k--) {
            int tx, ty;

            tx = x + dir[d][0];
            ty = y + dir[d][1];

            if (1 <= tx && tx <= n && 1 <= ty && ty <= m && s[tx][ty] != 'x') {
                x = tx;
                y = ty;

                if (s[x][y] != '0') {
                    s[x][y] = '0';
                    ans++;
                }
            } else {
                d = (d + 1) % 4;
            }
        }

        cout << ans << endl;
    }

    return 0;
}