#include<bits/stdc++.h>
using namespace std;
int n, m, k, x, y, d;
char Map[1001][1001];
bool vis[1001][1001];
inline void Move(){
    int xx, yy;
    if(d == 0) xx = x, yy = y + 1;
    if(d == 1) xx = x + 1, yy = y;
    if(d == 2) xx = x, yy = y - 1;
    if(d == 3) xx = x - 1, yy = y;
    if(xx >= 1 && xx <= n && yy >= 1 && yy <= m){
        if(Map[xx][yy] != 'x'){
            x = xx, y = yy;
            return;
        }
    }
    d = (d+1) % 4;
    return;
}
inline void Solve(){
    memset(vis, 0, sizeof(vis));
    cin >> n >> m >> k;
    cin >> x >> y >> d;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> Map[i][j];
        }
    }
    vis[x][y] = true;
    while(k--){
        Move();
        vis[x][y] = true;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(vis[i][j]){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return;
}
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        Solve();
    }
    return 0;
}