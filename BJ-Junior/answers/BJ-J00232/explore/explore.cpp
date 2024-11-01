#include <iostream>
using namespace std;
#define ll long long
ll T, n, m, k, x, y, d;
ll cx[10] = {0, 1, 0, -1};
ll cy[10] = {1, 0, -1, 0};
char g[1010][1010];
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while(T--) {
        ll cc = 0;
        bool vis[1010][1010] = {false};

        cin >> n >> m >> k;
        cin >> x >> y >> d;
        vis[x][y] = true;
        cc++;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> g[i][j];
            }
        }
        while(k > 0) {
            ll tx = x + cx[d];
            ll ty = y + cy[d];
            if(tx <= n && tx >= 1 && ty <= m && ty >= 1 && g[tx][ty] == '.') {
                if(vis[tx][ty] == false) {
                    cc++;
                }
                vis[tx][ty] = true;
                x = tx;
                y = ty;
                k--;
            }
            else {
                d = (d + 1) % 4;
                k--;
            }
        }
        cout << cc << endl;
    }


    return 0;
}
