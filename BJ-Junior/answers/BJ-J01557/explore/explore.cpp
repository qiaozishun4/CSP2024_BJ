#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    ll t, n, m, k, x, y, d, cnt, nx, ny;
    ll dx[10] = { 0, 1, 0, -1 };
    ll dy[10] = { 1, 0, -1, 0 };
    char tmp;
    cin >> t;
    while (t--) {
        bool a[1000][1000] = {};
        bool b[1000][1000] = {};
        cin >> n >> m >> k >> x >> y >> d;
        cnt = 1;
        b[x][y] = 1;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= m; j++) {
                cin >> tmp;
                a[i][j] = tmp == 'x';
            }
        }
        for (ll i = 0; i < k; i++) {
            nx = x + dx[d];
            ny = y + dy[d];
            if (!a[nx][ny] &&
                nx >= 1 && nx <= n
                && ny >= 1 && ny <= m)  {
                x = nx;
                y = ny;
                if (!b[x][y]) {
                    cnt++;
                }
            } else {
                d++;
                if (d == 4) {
                    d = 0;
                }
            }
            b[x][y] = 1;
        }
        cout << cnt << '\n';
    }

    return 0;
}
