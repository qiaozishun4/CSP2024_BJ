#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int N = 1e3 + 5;
int t;
char a[N][N];
int vis[N][N];
int d = 0, x, y;
int n, m, k;

bool check (int x, int y) {
    return x >= 1ll * 1 && x <= n && y >= 1ll * 1 && y <= m;
}

signed main () {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while (t--) {
        for (int i = 1; i <= 1005; i++) {
            for (int j = 1; j <= 1005; j++) {
                a[i][j] = ' ';
            }
        }
        memset(vis, 0, sizeof vis);

        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        vis[x][y] = 1;
        while (k--) {
            if (d == 0 && a[x][y + 1] != 'x' && check(x, y + 1) && a[x][y] != 'x') {
                vis[x][y + 1] = 1;
                y += 1;
            } else if (d == 1 && a[x + 1][y] != 'x' && check(x + 1, y) && a[x][y] != 'x') {
                vis[x + 1][y] = 1;
                x += 1;
            } else if (d == 2 && a[x][y - 1] != 'x' && check(x, y - 1) && a[x][y] != 'x') {
                vis[x][y - 1] = 1;
                y -= 1;
            } else if (d == 3 && a[x - 1][y] != 'x' && check(x - 1, y) && a[x][y] != 'x') {
                vis[x - 1][y] = 1;
                x -= 1;
            } else {
                d = (d + 1) % 4;
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (vis[i][j] == 1) {
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }


    return 0;
}
