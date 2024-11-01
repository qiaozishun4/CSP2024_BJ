#include<bits/stdc++.h>
using namespace std;

int t;
int d;
int x, y;
int n, m, k;
char c[1050][1050];
int f[1050][1050];
int cnt = 1;

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> c[i][j];
                f[i][j] = 0;
            }
        }
        cnt = 1;
        f[x][y] = 1;
        for (int i = 1; i <= k; i++) {
            if (d == 0) {
                if (1 <= x && x <= n && 1 <= (y + 1) && (y + 1) <= m && c[x][y + 1] != 'x') {
                    if (!f[x][y + 1]) {
                        x = x;
                        y = y + 1;
                        cnt++;
                        f[x][y] = 1;
                    }
                    else {
                        x = x;
                        y = y + 1;
                    }
                }
                else {
                    if (!f[x][y]) {
                        cnt++;
                        f[x][y] = 1;
                        d = (d + 1) % 4;
                    }
                    else {
                        d = (d + 1) % 4;
                    }
                }
            }
            else if (d == 1) {
                if (1 <= (x + 1) && (x + 1) <= n && 1 <= y && y <= m && c[x + 1][y] != 'x') {
                    if (!f[x + 1][y]) {
                        x = x + 1;
                        y = y;
                        cnt++;
                        f[x][y] = 1;
                    }
                    else {
                        x = x + 1;
                        y = y;
                    }
                }
                else {
                    if (!f[x][y]) {
                        cnt++;
                        f[x][y] = 1;
                        d = (d + 1) % 4;
                    }
                    else {
                        d = (d + 1) % 4;
                    }
                }
            }
            else if (d == 2) {
                if (1 <= x && x <= n && 1 <= (y - 1) && (y - 1) <= m && c[x][y - 1] != 'x') {
                    if (!f[x][y - 1]) {
                        x = x;
                        y = y - 1;
                        cnt++;
                        f[x][y] = 1;
                    }
                    else {
                        x = x;
                        y = y - 1;
                    }
                }
                else {
                    if (!f[x][y]) {
                        cnt++;
                        f[x][y] = 1;
                        d = (d + 1) % 4;
                    }
                    else {
                        d = (d + 1) % 4;
                    }
                }
            }
            else if (d == 3) {
                if (1 <= (x - 1) && (x - 1) <= n && 1 <= y && y <= m && c[x - 1][y] != 'x') {
                    if (!f[x - 1][y]) {
                        x = x - 1;
                        y = y;
                        cnt++;
                        f[x][y] = 1;
                    }
                    else {
                        x = x - 1;
                        y = y;
                    }
                }
                else {
                    if (!f[x][y]) {
                        cnt++;
                        f[x][y] = 1;
                        d = (d + 1) % 4;
                    }
                    else {
                        d = (d + 1) % 4;
                    }
                }
            }
            //cout << d << " " << x << " " << y << " " << f[x][y] << " " << cnt <<endl;
        }
        cout << cnt <<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
