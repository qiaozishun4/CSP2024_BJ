#include<bits/stdc++.h>
using namespace std;
char ma[1010][1010];
bool vis[1010][1010];
int tx, ty, nx, ny;
void nxt(int d){
    if(d == 0){
        ty += 1;
    }
    if(d == 1){
        tx += 1;
    }
    if(d == 2){
        ty -= 1;
    }
    if(d == 3){
        tx -= 1;
    }
    return ;
}
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    for(int l = 1; l <= t; l++){
        memset(vis, 0, sizeof(vis));
        int n, m, k, x, y, d, cnt = 1;
        cin >> n >> m >> k >> x >> y >> d;
        tx = x;
        ty = y;
        nx = x;
        ny = y;
        vis[x][y] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> ma[i][j];
            }
        }
        for(int h = 1; h <= k; h++){
            nxt(d);
            if(ma[tx][ty] != '.' || tx < 1 || tx > n || ty < 1 || ty > m){
                d = (d + 1) % 4;
                tx = nx;
                ty = ny;
            }
            else{
                nx = tx;
                ny = ty;
                //cout << nx << " " << ny << " " << vis[nx][ny] << endl;
                if(!vis[nx][ny]){
                    cnt++;
                    vis[nx][ny] = 1;
                }
            }
        }
        cout << cnt << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}