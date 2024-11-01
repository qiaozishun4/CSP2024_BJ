#include <iostream>
using namespace std;

char a[1005][1005];
bool vis[1005][1005];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T; cin >>T;
    while (T--){
        int n, m, k, x0, y0, d0; cin >> n >> m >> k >> x0 >> y0 >> d0;
        for (int i = 1; i <= n; i++){
                for (int j = 1; j <= m; j++)
            cin >> a[i][j];
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                vis[i][j] = false;
            }
        }
        int x = x0, y = y0, d = d0, ans = 1;
        vis[x][y] = true;
        for (int i = 1; i <= k; i++){
            if (a[x+dx[d]][y+dy[d]] == 'x' || 0 >= dx[d]+x || x+dx[d] > n
                || y+dy[d] <= 0 || y+dy[d] > m)
            d = (d+1) % 4;
            else{
                x = x + dx[d], y = y+dy[d];
                if (!vis[x][y]) ans++;
                vis[x][y] = true;
            }
            //cout << x << " " << y << " " << d <<  endl;
        }
        /*for (int i = 1; i <= n; i++){
                for (int j = 1; j <= m; j++)
            cout << vis[i][j];
            cout << endl;
        }*/
        cout << ans << endl;
    }
return 0;}
