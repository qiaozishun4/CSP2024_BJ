#include<bits/stdc++.h>
using namespace std;
char c[1005][1005];
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t, n, m, k, nx, ny, d;
    scanf("%d", &t);
    while(t--){
        int cnt = 1;
        scanf("%d%d%d%d%d%d", &n, &m, &k, &nx, &ny, &d);
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cin>>c[i][j];
            }
        }
        c[nx][ny] = 'a';
        while(k--){
            bool f = 0;
            int xx = nx + dx[d], yy = ny + dy[d];
            if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && c[xx][yy] != 'x'){
                nx += dx[d], ny += dy[d];
                if(c[nx][ny] == '.') cnt++, c[nx][ny] = 'a';
                continue;
            }
            d = (d + 1) % 4;
            //printf("(%d %d)\n", nx, ny);
        }
        /*
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                printf("%c", c[i][j]);
            }
            printf("\n");
        }
        */
        printf("%d\n", cnt);

    }
    return 0;
}
