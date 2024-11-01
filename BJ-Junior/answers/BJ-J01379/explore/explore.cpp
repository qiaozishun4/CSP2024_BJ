#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[1024][1024], vis[1024][1024];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;
int cnt;

void dfs(int x, int y, int d, int k){
    if (k == 0){
        if (vis[x][y] == 0) cnt++;
        return;
    }
    int xx = x+dx[d], yy = y+dy[d];
    if (xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]!=1){
        if (vis[xx][yy]==0){
            cnt++;
        }
        vis[xx][yy] = 1;
        dfs(xx, yy, d, k-1);
    }else{
        dfs(x, y, (d+1)%4, k-1);
    }
}

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while (T--){
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        cnt = 1;
        int k;
        cin >> n >> m >> k;
        int sx, sy, sd;
        cin >> sx >> sy >> sd;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                char c;
                cin >> c;
                if (c == 'x') a[i][j] = 1;
            }
        }
        vis[sx][sy] = 1;
        dfs(sx, sy, sd, k);
        cout << cnt << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
