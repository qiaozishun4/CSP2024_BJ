#include <bits/stdc++.h>
using namespace std;
char a[1010][1010];
int vis[1010][1010], f[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    int n, m, k, x, y, d, ans;
    cin >> T;
    while (T--){
        ans = 1;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];
                // a[i][j] = a[i][j] == '.' ? 0 : 1;
                vis[i][j] = 0;
            }
        }
        vis[x][y] = 1;
        while (k--){
            int nx = x+f[d][0], ny = y+f[d][1];
            if (nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == 'x'){
                d = (d+1) % 4;
                continue;
            }
            x = nx, y = ny;
            if (vis[x][y] == 0) ans++;
            vis[x][y] = 1;
            // cout << nx << ' ' << ny << endl;
        }
        cout << ans << endl;
    }
    return 0;
}

