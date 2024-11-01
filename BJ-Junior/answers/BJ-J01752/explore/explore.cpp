// By Pr_159
// Sugar_Pigeon & 159 rp++!

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e3 + 5;

int T, n, m, k, x, y, d;
bool vis[N][N];
char G[N][N];

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--) {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                cin >> G[i][j];
                vis[i][j] = 0;
            }
        }
        vis[x][y] = 1;
        LL ans = 1;
        for(int i = 1; i <= k; ++i) {
            int nx = x, ny = y;
            if(d == 0) {
                ++ny;
            } else if(d == 1) {
                ++nx;
            } else if(d == 2) {
                --ny;
            } else {
                --nx;
            }
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && G[nx][ny] == '.') {
                if(!vis[nx][ny]) {
                    ++ans;
                    vis[nx][ny] = 1;
                }
                x = nx, y = ny;
            } else {
                d = (d + 1) % 4;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
