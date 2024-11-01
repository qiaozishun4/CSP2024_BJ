#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    for (int q = 0; q < T; q++) {
        int n, m, k;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        x--;
        y--;
        char maps[n][m] = {};
        bool is[n][m] = {};
        is[x][y] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> maps[i][j];
            }
        }
        for (int i = 0; i < k; i++) {
            int lu[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1 , 0}};
            int x1 = x + lu[d][0], y1 = y + lu[d][1];
            if (x1 >= n || x1 < 0 || y1 >= m || y1 < 0) {
                d = (d + 1) % 4;
                continue;
            }
            if (maps[x1][y1] == 'x') {
                d = (d + 1) % 4;
                continue;
            }
            x = x1, y = y1;
            is[x][y] = true;
        }
        int r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                r += is[i][j];
            }
        }
        cout << r << endl;
    }
    return 0;
}
