#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
char s[1005][1005];
bool a[1005][1005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T; cin >> T;
    while (T--) {
        memset(a, 0, sizeof(a));
        int n, m, k; cin >> n >> m >> k;
        int x, y, d; cin >> x >> y >> d;
        for (int i = 1; i <= n; i++) {
            cin >> (s[i] + 1);
        }
        a[x][y] = 1;
        int nx, ny;
        while (k--) {
            nx = x + dx[d], ny = y + dy[d];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && s[nx][ny] != 'x') {
                x = nx, y = ny;
                a[x][y] = 1;
            } else {
                d = (d + 1) % 4;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j]) ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
