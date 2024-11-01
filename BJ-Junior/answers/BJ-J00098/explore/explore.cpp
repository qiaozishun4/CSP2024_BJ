#include <bits/stdc++.h>
using namespace std;

long long n, m, k, x, y, d, t, ans = 1;
char mp[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool is[1005][1005];

void move () {
    if (mp[x + dx[d]][y + dy[d]] == '.' && x + dx[d] >= 1 && x + dx[d] <= n && y + dy[d] >= 1 && y + dy[d] <= m) {
        x += dx[d];
        y += dy[d];
        if (is[x][y] == 0) {
            ans++;
            is[x][y] = 1;
        }
    } else {
        d = (d + 1) % 4;
    }
}

int main () {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n >> m >> k >> x >> y >> d;
        is[x][y] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> mp[i][j];
            }
        }
        for (int i = 1; i <= k; ++i) {
            move();
        }
        cout << ans << "\n";
        ans = 1;
        for (int i = 1; i <= 1000; ++i) {
            for (int j = 1; j <= 1000; ++j) {
                is[i][j] = 0;
            }
        }
    }
    return 0;
}
