#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int T, n, m, Q, x, y, d, ans;
char a[1010][1010];

bool in(int x, int y) { return 1 <= x && x <= n && 1 <= y && y <= m; }

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while (T--){
        cin >> n >> m >> Q >> x >> y >> d;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        a[x][y] = 'Y'; ans = 1;
        while (Q--){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!in(nx, ny) || a[nx][ny] == 'x'){
                d = (d + 1) % 4; continue;
            }
            x = nx; y = ny;
            if (a[x][y] != 'Y'){
                ans++;
                a[x][y] = 'Y';
            }
        }
        cout << ans << endl;
    }
    return 0;
}
