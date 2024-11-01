// explore
#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;

const int cap = 1010;
bool bl[cap][cap];
bool vis[cap][cap];
const int X[] = {0, 1, 0, -1};
const int Y[] = {1, 0, -1, 0};

const char _DEBUG_D[] = "ESWN";

void solve() {
    memset(vis, 0, sizeof(vis));
    memset(bl, 0, sizeof(bl));
    int n, m, k;
    cin >> n >> m >> k;
    int x0, y0, d0;
    cin >> x0 >> y0 >> d0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch;
            cin >> ch;
            if (ch == 'x') bl[i][j] = 1;
            else bl[i][j] = 0;
        }
    }


    int x = x0, y = y0, d = d0;
    int nx, ny;
    int ans = 1;
    vis[x][y] = 1;
    while (k--) {
        nx = x + X[d], ny = y + Y[d];
        if (bl[nx][ny] || nx < 1 || nx > n || ny < 1 || ny > m) {
            d = (d + 1) % 4;
//            cout << "(" << nx << ", " << ny << ") " << "NOT IN MAP. TURN RIGHT\n";
            continue;
        }
        x = nx, y = ny;
//        cout << "GO " << _DEBUG_D[d] << " TO " << x << " " << y << endl;
        if (vis[x][y] == 0) {
            ans++;
        }
        vis[x][y] = 1;
    }
    cout << ans << endl;
}

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
	return 0;
}
