#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int go[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int vis[1005][1005] = {0};
int n = 0, m = 0, k = 0;
char Map[1005][1005];
bool check(int x, int y){
    if(x >= 1 && x <= n && y >= 1 && y <= m && Map[x][y] == '.'){
        return 1;
    } else {
        return 0;
    }
}
void dfs(int x, int y, int d, int t){
    while(1){
        vis[x][y] = 1;
        if(t > k){
            return;
        }
        int u = x + go[d][0], v = y + go[d][1];
        if(check(u, v) == 1){
            x = u, y = v, t++;
        } else {
            while(check(u, v) == 0 && t <= k){
                d = (d + 1) % 4;t++;
                u = x + go[d][0], v = y + go[d][1];
            }
            if(t <= k){
                x = u, y = v, t++;
            }
        }
    }
    return;
}
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t = 0;
    cin >> t;
    while(t--){
        memset(vis, 0, sizeof(vis));
        int x = 0, y = 0, d = 0, ans = 0;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1; i <= n; i++){
            string str;
            cin >> str;
            for(int j = 1; j <= m; j++){
               Map[i][j] = str[j - 1];
            }
        }
        dfs(x, y, d, 1);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(vis[i][j] == 1){
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
