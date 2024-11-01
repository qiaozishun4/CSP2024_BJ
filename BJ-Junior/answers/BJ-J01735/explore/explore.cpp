#include <bits/stdc++.h>
using namespace std;
long long T, n, m, k;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool vis[1010][1010];
char mp[1010][1010];
bool check(int x, int y){
    if (x < 1 || y < 1 || x > n || y > m) return 0;
    if (mp[x][y] == 'x') return 0;
    return 1;
}
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while(T--){
        //初始化
        memset(vis, 0, sizeof vis);
        long long ans = 1;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        vis[x][y] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> mp[i][j];
            }
        }
        //开始k次操作
        while(k--){
//            cout << "x:" << x << " y:" << y << " d:" << d << "\n";
            if (check(x + dx[d], y + dy[d])){ //下个位置可以走
                x += dx[d], y += dy[d];
                if (vis[x][y] == 0) ans++;
                vis[x][y] = 1;
                continue;
            }
            else{ //不能走
                d = (d + 1) % 4; //右转
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
