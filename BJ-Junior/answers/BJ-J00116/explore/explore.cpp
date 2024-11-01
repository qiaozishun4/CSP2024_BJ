#include <bits/stdc++.h>
using namespace std;
int T;
int d[4][2] = {{0, 1},
               {1, 0},
               {0, -1},
               {-1, 0}};
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while (T--) {
        int n, m, k, xs, ys, d0, ans = 0;
        char mp[1005][1005] = {{}};
        cin >> n >> m >> k >>xs >> ys >>d0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> mp[i][j];
            }
        }
        int xn, yn, dn;
        xn = xs, yn = ys, dn = d0;
        mp[xn][yn] = '1';
        for (int i = 1; i <= k; i++) {
            int xe = xn + d[dn][0], ye = yn + d[dn][1];
            while (mp[xe][ye] == 'x' || xe < 1 || xe > n || ye < 1 || ye > m) {
                ++dn;
                if (dn >3) dn-=4;
                xe = xn, ye = yn;
            }
            xn = xe, yn = ye;
            mp[xn][yn] = '1';
        }

        for (int i = 1; i <= n; i++)  {
            for (int j = 1; j <= m; j++) {
                if (mp[i][j] == '1') ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
