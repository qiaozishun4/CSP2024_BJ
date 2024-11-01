#include <bits/stdc++.h>
using namespace std;

bool vis[1005][1005], mp[1005][1005];
void init() {
    for (int i = 0; i < 1005; i++)
        for (int j = 0; j < 1005; j++) {
            mp[i][j] = 0;
            vis[i][j] = 0;
        }
    return;
}
void solve () {
    int n, m, k, x, y, d, ans = 0;
    char c;
    cin >> n >> m >> k >> x >> y >> d;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
        cin >> c;
        if (c == '.')
            mp[i][j] = 1;
    }
    int x_n, y_n;
    while (k--) {
        if (!vis[x][y])
            ans++;
        vis[x][y] = 1;
        x_n = x;
        y_n = y;
        if (d == 0)
            y_n++;
        if (d == 1)
            x_n++;
        if (d == 2)
            y_n--;
        if (d == 3)
            x_n--;
        if (mp[x_n][y_n]) {
            x = x_n;
            y = y_n;
        }
        else
            d = (d + 1) % 4;
        if (!vis[x][y])
            ans++;
        vis[x][y] = 1;
    }
    cout << ans << endl;
    return;
}
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    int T;
    cin >> T;
    while (T--) {
        init();
        solve();
    }
    return 0;
}
