#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
char a[N][N];
bool vis[N][N];
int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
freopen("explore.in", "r", stdin);
freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        int n, m, k;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        vis[x][y] = true;
        for (int i = 1; i <= k; i++) {
            int nx = x + direction[d][0];
            int ny = y + direction[d][1];
            if (nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == 'x') {
                d = (d + 1) % 4;
                continue;
            }
            x = nx, y = ny;
            vis[x][y] = true;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ans += vis[i][j];
                vis[i][j] = false;
            }
        }
        cout << ans << endl;
    }
    return 0;
}