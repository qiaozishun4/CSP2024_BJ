#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
bool map_[N][N],vis[N][N];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        for (int i = 1 ; i <= 1e3 ; i++){
            for (int j = 1; j <= 1e3 ; j++){
                map_[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        int n,m,k,x,y,d,ans = 1;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1 ; i <= n ; i++){
            for (int j = 1; j <= m ; j++){
                char c;
                cin >> c;
                if (c == 'x') map_[i][j] = 0;
                else if (c == '.') map_[i][j] = 1;
            }
        }
        vis[x][y] = 1;
        while(k--){
            int nx,ny;
            if (d == 0){
                nx = x, ny = y + 1;
                if (nx < 1 || nx > n || ny < 1 || ny > m || !map_[nx][ny]){
                    nx = x; ny = y;
                    d = (d + 1) % 4;
                }
            }
            else if (d == 1){
                nx = x + 1, ny = y;
                if (nx < 1 || nx > n || ny < 1 || ny > m || !map_[nx][ny]){
                    nx = x; ny = y;
                    d = (d + 1) % 4;
                }
            }
            else if (d == 2){
                nx = x, ny = y - 1;
                if (nx < 1 || nx > n || ny < 1 || ny > m || !map_[nx][ny]){
                    nx = x; ny = y;
                    d = (d + 1) % 4;
                }
            }
            else if (d == 3){
                nx = x - 1, ny = y;
                if (nx < 1 || nx > n || ny < 1 || ny > m || !map_[nx][ny]){
                    nx = x; ny = y;
                    d = (d + 1) % 4;
                }
            }
            x = nx; y = ny;
            if (!vis[x][y]){
                vis[x][y] = 1;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
