#include <bits/stdc++.h>
#define int long long
using namespace std;
char data[1005][1005];
bool vis[1005][1005];
signed main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        memset(data, 0, sizeof data);
        memset(vis, false, sizeof vis);
        int n, m, k;
        cin >> n >> m >> k;
        int s_x, s_y, s_d;
        cin >> s_x >> s_y >> s_d;
        for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) cin >> data[i][j];
        vis[s_x][s_y] = true;
        int x = s_x, y = s_y, d = s_d;
        int ans = 1;
        while(k--){
            int nx, ny;
            if(d == 0){
                nx = x;
                ny = y+1;
            }
            else if(d == 1){
                nx = x+1;
                ny = y;
            }
            else if(d == 2){
                nx = x;
                ny = y-1;
            }
            else{
                nx = x-1;
                ny = y;
            }
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && data[nx][ny] == '.'){
                if(!vis[nx][ny]) ans++;
                vis[nx][ny] = true;
                x = nx;
                y = ny;
            }
            else d = (d+1)%4;
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
