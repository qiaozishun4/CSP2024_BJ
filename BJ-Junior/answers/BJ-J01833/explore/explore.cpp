#include <iostream>
#include <cstring>
using namespace std;
int a[1005][1005];
int dx[10] = {0, 1, 0, -1};
int dy[10] = {1, 0, -1, 0};
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while (T --){
        long long n, m, k, x, y, d, ans = 0;
        cin >> n >> m >> k >> x >> y >> d;
        memset(a, 0, sizeof a);
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++){
                char c;
                cin >> c;
                if (c == 'x')
                    a[i][j] = 1;
                else a[i][j] = 0;
            }
        a[x][y] = 2;
        while (k --){
            int xx = x + dx[d], yy = y + dy[d];
            if (xx > 0 && xx <= n && yy > 0 && yy <= m && a[xx][yy] != 1)
                x = xx, y = yy, a[xx][yy] = 2;
            else d = (d + 1) % 4;
        }
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
                if (a[i][j] == 2) ans ++;
        cout << ans << endl;
    }
    return 0;
}
