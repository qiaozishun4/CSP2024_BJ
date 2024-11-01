#include<bits/stdc++.h>
using namespace std;
int T, n, m, k, x, y, d;
char mp[1010][1010];
bool vis[1010][1010];
int dx[5] = {0, 1, 0, -1};
int dy[5] = {1, 0, -1, 0};
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while(T--) {
        int ans = 1;
        memset(vis, 0, sizeof(vis));
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> mp[i][j];
            }
        }
        vis[x][y] = 1;
        for(int i = 1; i <= k; i++) {
            int nx = x+dx[d], ny = y+dy[d];
            if(nx<1||ny<1||nx>n||ny>m||mp[nx][ny]=='x') d = (d+1)%4;
            else {
                x = nx, y = ny;
                if(!vis[x][y]) {
                    ans++;
                    vis[x][y] = 1;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}