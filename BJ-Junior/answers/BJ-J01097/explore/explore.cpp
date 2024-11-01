#include<bits/stdc++.h>
using namespace std;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int t;
int vis[1010][1010];
int n, m, k, x, y, d, ans;
char a[1010][1010];
void bfs(int sx, int sy, int sd, int op)
{
    while(op >= 0){
        if(op == 0){
            vis[sx][sy] = 1;
            break;
        }
        int xx = sx + dx[sd], yy = sy + dy[sd], nextd = sd, flag = 0;
        if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy] == '.'){
            flag = 1;
        }
        else {
            for(int i = 1; i <= 3; i++){
                nextd = (sd + i) % 4;
                xx = sx + dx[nextd], yy = sy + dy[nextd];
                op--;
                if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy] == '.'){
                    flag = 1;
                    break;
                }
                if(op == 0) break;
            }
        }
        vis[sx][sy] = 1;
        if(flag){
            op--;
            sx = xx, sy = yy, sd = nextd;
        }else{
            break;
        }
    }
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        memset(a, '\0', sizeof(a));
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        bfs(x, y, d, k);
        ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(vis[i][j]) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
