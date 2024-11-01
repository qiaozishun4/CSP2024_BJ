#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<bool>> a(n, vector<bool>(m, true));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int x, y, d;
        cin >> x >> y >> d;
        x--;
        y--;
        vis[x][y] = true;
        char tmp_c;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> tmp_c;
                if (tmp_c == 'x') {
                    a[i][j] = false;
                }
            }
        }
        int ans = 1;
        while(k--) {
            int x1 = x;
            int y1 = y;
            if (d == 0) {
                y1++;
            } else if (d == 1) {
                x1++;
            } else if (d == 2) {
                y1--;
            } else if (d == 3) {
                x1--;
            }
            if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && a[x1][y1]) {
                x = x1;
                y = y1;
                if (!vis[x][y]) {
                    ans++;
                    vis[x][y] = true;
                }
            } else {
                d = (d + 1) % 4;
            }
        }
        cout << ans << endl;
    }
    return 0;
}