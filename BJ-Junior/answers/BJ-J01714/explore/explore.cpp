#include<bits/stdc++.h>
using namespace std;
char c[1005][1005];
bool vis[1005][1005];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        int n, m, k;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= m;j++){
                cin >> c[i][j];
            }
        }
        int cnt = 1;
        memset(vis, 0, sizeof (vis));
        vis[x][y] = 1;
        while (k--){
            int nx, ny;
            if (d == 0){
                nx = x;
                ny = y + 1;
            }
            if (d == 1){
                nx = x + 1;
                ny = y;
            }
            if (d == 2){
                nx = x;
                ny = y - 1;
            }
            if (d == 3){
                nx = x - 1;
                ny = y;
            }
            if (nx < 1 || ny < 1 || nx > n || ny > m || c[nx][ny] == 'x'){
                d = (d + 1) % 4;
            }
            else{
                x = nx;
                y = ny;
                if (!vis[x][y]){
                    vis[x][y] = 1;
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
