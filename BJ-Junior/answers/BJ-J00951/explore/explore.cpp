#include <cstdio>
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t, n, m, k, x, y, d, nx, ny, cnt, dx[10] = {0, 1, 0, -1}, dy[10] = {1, 0, -1, 0};
    char a[1005][1005];
    bool vis[1005][1005];
    scanf("%d", &t);
    while(t--){
        cnt = 1;
        scanf("%d %d %d\n%d %d %d", &n, &m, &k, &x, &y, &d);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                scanf(" %c", &a[i][j]);
                vis[i][j] = 0;
            }
        }
        vis[x][y] = 1;
        while(k--){
            nx = x + dx[d];
            ny = y + dy[d];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.'){
                x = nx;
                y = ny;
                if(!vis[x][y]){
                    cnt++;
                    vis[x][y] = 1;
                }
            }else{
                d = (d + 1) % 4;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
