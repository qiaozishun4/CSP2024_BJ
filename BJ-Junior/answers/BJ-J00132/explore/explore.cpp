#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
long long cnt = 0;
long long n, m, k;
bool vis[maxn][maxn];
char c[maxn][maxn];
void dfs(int x, int y, int d){
    if(k <= 0) return;
    int nx, ny;
    if(d == 0){
        nx = x, ny = y + 1;
        if(nx > n || ny > m || nx < 1 || ny < 1 || c[nx][ny] == 'x'){
            d = (d + 1) % 4;
            k--;
            dfs(x, y, d);
            return;
        }else{
            if(!vis[nx][ny]){
                cnt++;
                vis[nx][ny] = 1;
            }
            k--;
            dfs(nx, ny, d);
            return;
        }
    }else if(d == 1){
        nx = x + 1, ny = y;
        if(nx > n || ny > m || nx < 1 || ny < 1 || c[nx][ny] == 'x'){
            d = (d + 1) % 4;
            k--;
            dfs(x, y, d);
            return;
        }else{
            if(!vis[nx][ny]){
                cnt++;
                vis[nx][ny] = 1;
            }
            k--;
            dfs(nx, ny, d);
            return;
        }
    }else if(d == 2){
        nx = x, ny = y - 1;
        if(nx > n || ny > m || nx < 1 || ny < 1 || c[nx][ny] == 'x'){
            d = (d + 1) % 4;
            k--;
            dfs(x, y, d);
            return;
        }else{
            if(!vis[nx][ny]){
                cnt++;
                vis[nx][ny] = 1;
            }
            k--;
            dfs(nx, ny, d);
            return;
        }
    }else if(d == 3){
        nx = x - 1, ny = y;
        if(nx > n || ny > m || nx < 1 || ny < 1 || c[nx][ny] == 'x'){
            d = (d + 1) % 4;
            k--;
            dfs(x, y, d);
            return;
        }else{
            if(!vis[nx][ny]){
                cnt++;
                vis[nx][ny] = 1;
            }
            k--;
            dfs(nx, ny, d);
            return;
        }
    }
}
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++) cin >> c[i][j];
        }
        cnt = 1;
        memset(vis, 0, sizeof(vis));
        vis[x][y] = 1;
        dfs(x, y, d);
        cout << cnt << '\n';
    }
    return 0;
}