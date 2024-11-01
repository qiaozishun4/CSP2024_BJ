#include <bits/stdc++.h>
using namespace std;
int mp[1005][1005];
int T;
int n, m, k;
int x, y, d;
const int gox[4] = {0, 1, 0, -1};
const int goy[4] = {1, 0, -1, 0};
int v[1005][1005];
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while (T--) {
        memset(mp, 0, sizeof(mp));
        memset(v, 0, sizeof(v));
        cin >> n >> m >> k >> x >> y >> d;
        v[x][y] = 1;
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char t;
                cin >> t;
                if (t == 'x')  mp[i][j] = 0;
                else  mp[i][j] = 1;
            }
        }
        while (k--) {
            int tx = x + gox[d], ty = y + goy[d];
            if (mp[tx][ty]) {
                if (v[tx][ty] == 0) {
                    v[tx][ty] = 1;
                    ans++;
                }
                x = tx, y = ty;
            } else {
                d = (d + 1) % 4;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
