#include <bits/stdc++.h>
using namespace std;
char c[1001][1001];
bool vis[1001][1001];
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> c[i][j];
            }
        }
        for (int i = 1; i <= k; ++i) {
            if (d == 0) {
                if (c[x][y+1] == '.') {
                    vis[x][++y] = 1;
                } else {
                    d = 1;
                }
            }
            if (d == 1) {
                if (c[x+1][y] == '.') {
                    vis[++x][y] = 1;
                } else {
                    d = 2;
                }
            }
            if (d == 2) {
                if (c[x][y-1] == '.') {
                    vis[x][--y] = 1;
                } else {
                    d = 3;
                }
            }
            if (d == 3) {
                if (c[x-1][y] == '.') {
                    vis[--x][y] = 1;
                } else {
                    d = 0;
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (vis[i][j]) {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
