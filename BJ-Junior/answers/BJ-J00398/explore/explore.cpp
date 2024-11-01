#include <bits/stdc++.h>
using namespace std;
const int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m, k, x, y, dir, vis[1005][1005];
char mp[1005][1005];
void solve(){
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    cin >> n >> m >> k >> x >> y >> dir;
    for (int i = 1;i <= n;i++) for (int j = 1;j <= m;j++) cin >> mp[i][j];
    vis[x][y] = 1; ans++;
    for (int i = 1;i <= k;i++){
        int nx = x + d[dir][0], ny = y + d[dir][1];
        if (nx && nx <= n && ny && ny <= m && mp[nx][ny] == '.'){
            if (vis[nx][ny] == 0) ans++;
            vis[nx][ny] = 1;
            x = nx; y = ny;
        } else dir = (dir + 1) % 4;
    } cout << ans << endl;
} int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
