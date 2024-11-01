#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    int delta[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    int t;
    cin >> t;

    while(t--) {
        int n, m, k, x, y, d, ans{1};
        cin >> n >> m >> k >> x >> y >> d;
        x--; y--;

        bool b[n][m];
        memset(b, 0, sizeof(b));
        b[x][y] = 1;

        string area[n];
        for(int i{0}; i < n; i++) {
            cin >> area[i];
        }

        while(k--) {
            int nx, ny;
            nx = x + delta[d][0];
            ny = y + delta[d][1];
            if(nx < 0 or nx >= n or ny < 0 or ny >= m or area[nx][ny] == 'x') {
                d = (d + 1) % 4;
            } else {
                x = nx; y = ny;
                if(b[x][y] == 0) ans++;
                b[x][y] = 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
