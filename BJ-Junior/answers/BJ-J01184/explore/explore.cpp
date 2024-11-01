#include <bits/stdc++.h>
using namespace std;
int T, n, m, k, x, y, d;
char a[1005][1005];
int dx[5] = {0, 1, 0, -1}, dy[5] = {1, 0, -1, 0};
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin>>T;
    while(T--){
        long long cnt = 0;
        bool vis[1005][1005] = {};
        cin>>n>>m>>k>>x>>y>>d;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        vis[x][y] = 1;
        while(k--){
            int tx = x + dx[d], ty = y + dy[d];
            if(tx >= 1 && tx<=n && ty >= 1 && ty <= m && a[tx][ty] == '.'){
                x = tx;
                y = ty;
                if(vis[x][y] == 0){
                    vis[x][y] = 1;
                }
            }
            else{
                d = (d + 1) % 4;
            }
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                cnt += vis[i][j];
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
