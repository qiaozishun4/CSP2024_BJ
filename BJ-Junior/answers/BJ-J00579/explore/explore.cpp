#include <bits/stdc++.h>
using namespace std;
int T;
char c[1010][1010];
bool vis[1005][1005];
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while(T--) {
        int n, m, k;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        memset(vis, 0, sizeof(vis));
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                cin >> c[i][j];
        vis[x][y] = 1;
        while(k--) {
            int xx, yy;
            if(d == 0) {
                xx = x, yy = y + 1;
            }
            else if(d == 1) {
                xx = x + 1, yy = y;
            }
            else if(d == 2) {
                xx = x, yy = y - 1;
            }
            else if(d == 3) {
                xx = x - 1, yy = y;
            }
            if(xx < 1 || xx > n || yy < 1 || yy > m || c[xx][yy] == 'x') {
                d = (d + 1) % 4;
                continue;
            }
            x = xx, y = yy;
            vis[xx][yy] = 1;
        }
        int ans = 0;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                ans += vis[i][j];
        cout << ans << endl;
    }
    return 0;
}