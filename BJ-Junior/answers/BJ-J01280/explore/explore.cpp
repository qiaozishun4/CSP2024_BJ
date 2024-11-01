#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int dxy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    for (int z = 0;z < T;z++) {
        bool ma[N][N][2];
        int n, m, k, x, y, d, cnt = 1;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++) {
                char in;
                cin >> in;
                ma[i][j][0] = 0;
                ma[i][j][1] = 0;
                if (in == 'x') ma[i][j][0] = 1;
            }
        x--, y--;
        ma[x][y][1] = 1;
        for (int k_ = 0;k_ < k;k_++) {
            int dx = x + dxy[d][0], dy = y + dxy[d][1];
            if (dx >= n || dx < 0 || dy >= m || dy < 0 || ma[dx][dy][0]) d = (d + 1) % 4;
            else {
                x = dx, y = dy;
                cnt += 1 - ma[x][y][1];
                ma[x][y][1] = 1;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
