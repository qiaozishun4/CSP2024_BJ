#include <bits/stdc++.h>
using namespace std;

int T, n, m, k, x, y, d, G[1007][1007] = {0}, step, x_update, y_update;
string a;

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    cin >> T;
    for (int s = 0; s < T; s++) {
        step = 1;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            for (int j = 1; j <= m; j++) {
                if (a[j-1] == 'x') G[i][j] = 1;
                else G[i][j] = 0;
            }
        }
        G[x][y] = 2;
        for (int i = 0 ; i < k; i++) {
            if (d == 0) x_update = x, y_update = y + 1;
            else if (d == 1) x_update = x + 1, y_update = y;
            else if (d == 2) x_update = x, y_update = y - 1;
            else if (d == 3) x_update = x - 1, y_update = y;
            if (x_update >= 1 && x_update <= n && y_update >= 1 && y_update <= m && G[x_update][y_update] != 1) {
                x = x_update, y = y_update;
                if (G[x][y] == 0) {
                    G[x][y] = 2;
                    step++;
                }
            }
            else d = (d + 1) % 4;
        }
        cout << step << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}