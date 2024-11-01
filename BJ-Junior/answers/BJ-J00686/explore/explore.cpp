#include <bits/stdc++.h>
using namespace std;

long long T, n, m, x, y, d, t, cnt, a[1005][1005];
char ch;

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n >> m >> t >> x >> y >> d;
        cnt = 0;
        for (long long i = 1; i <= n; i++) {
            for (long long j = 1; j <= m; j++) {
                cin >> ch;
                if (ch == '.') {
                    a[i][j] = 0;
                } else {
                    a[i][j] = 2;
                }
            }
        }
        a[x][y] = 1;
        cnt++;
        for (long long i = 1; i <= t; i++) {
            if (d == 0) {
                if (a[x][y + 1] != 2 && y + 1 <= m) {
                    y++;
                    if (a[x][y] == 0) {
                        cnt++;
                        a[x][y]++;
                    }
                } else {
                    d = 1;
                }
            } else if (d == 1) {
                if (a[x + 1][y] != 2 && x + 1 <= n) {
                    x++;
                    if (a[x][y] == 0) {
                        cnt++;
                        a[x][y]++;
                    }
                } else {
                    d = 2;
                }
            } else if (d == 2) {
                if (a[x][y - 1] != 2 && 1 <= y - 1) {
                    y--;
                    if (a[x][y] == 0) {
                        cnt++;
                        a[x][y]++;
                    }
                } else {
                    d = 3;
                }
            } else {
                if (a[x - 1][y] != 2 && 1 <= x - 1) {
                    x--;
                    if (a[x][y] == 0) {
                        cnt++;
                        a[x][y]++;
                    }
                } else {
                    d = 0;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}