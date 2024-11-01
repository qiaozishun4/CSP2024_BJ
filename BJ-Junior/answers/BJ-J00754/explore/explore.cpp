#include <bits/stdc++.h>
using namespace std;

char a[1005][1005];
bool vis[1005][1005];
int T,
nex[] = { 0,  1,  0, -1},
ney[] = { 1,  0, -1,  0};

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while (T --) {
        int n, m, k, x, y, d, ans = 0;
        cin >> n >> m >> k >> x >> y >> d;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                cin >> a[i][j];
                vis[i][j] = 0;
            }
        }
        vis[x][y] = 1;
        while (k --) {
            if(a[x + nex[d]][y + ney[d]] == '.') {
                x += nex[d];
                y += ney[d];
                vis[x][y] = 1;
            } else {
                d = (d + 1) % 4;
            }
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                if (vis[i][j]) {
                    ans ++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
