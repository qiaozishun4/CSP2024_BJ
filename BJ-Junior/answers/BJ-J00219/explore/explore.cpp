#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int a[1005][1005];
int n, m, k;
int x, y, d;
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int Q; cin >> Q;
    while (Q--) {
        int ans = 0;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                char tmp; cin >> tmp;
                if (tmp == '.') a[i][j] = 1;
                else a[i][j] = 0;
            }
        for (int i = 1; i <= k; ++i) {
            int x1 = x + dx[d], y1 = y + dy[d];
            if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && a[x1][y1]) x = x1, y = y1, ans++;
            else d = (d + 1) % 4;
        }
        cout << ans << endl;
    }
}
