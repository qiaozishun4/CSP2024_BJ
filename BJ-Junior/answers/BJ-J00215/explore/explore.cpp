#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1010;
int  vis[N][N];
char c[N][N];
int dx[] = {0 , 1 , 0 , -1} , dy[] = {1 , 0 , -1 , 0};
int main(){
    freopen("explore.in" , "r" , stdin);
    freopen("explore.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n , m , k , x , y , d;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> c[i][j];
        memset(vis , 0 , sizeof(vis));
        vis[x][y] = 1;
        while (k--){
            int nx = x + dx[d] , ny = y + dy[d];
            if (nx < 1 || nx > n || ny < 1 || ny > m || c[nx][ny] == 'x')d = (d + 1) % 4;
            else{
                x = nx;
                y = ny;
            }
            vis[x][y] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                ans += vis[i][j];
        cout << ans << '\n';
    }
    return 0;
}
//9.24