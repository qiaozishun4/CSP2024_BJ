#include <bits/stdc++.h>
using namespace std;

char mp[1005][1005];
bool vis[1005][1005];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, k, x, y, d, ans = 0;
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                vis[i][j] = 0;
                cin >> mp[i][j];
            }
        }
        vis[x][y] = 1;
        while(k--){
            if(mp[x + dx[d]][y + dy[d]] == '.'){
                x += dx[d]; y += dy[d];
                vis[x][y] = 1;
            }else{
                d = (d + 1) % 4;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(vis[i][j] == 1){
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
