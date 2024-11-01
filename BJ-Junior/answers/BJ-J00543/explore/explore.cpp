#include <bits/stdc++.h>
using namespace std;
const int N = 1007;
int T, n, m, k, x, y, d, cnt;
char ch[N][N];
bool flag[N][N];
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        memset(flag, 0, sizeof(flag));
        flag[x][y] = 1, cnt = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> ch[i][j];
            }
        }
        while (k--) {
            if (d == 0) {
                if (y + 1 <= m && ch[x][y + 1] == '.') y += 1;
                else d = (d + 1) % 4;
                if (!flag[x][y]) cnt++, flag[x][y] = 1;
            }
            else if (d == 1) {
                if (x + 1 <= n && ch[x + 1][y] == '.') x += 1;
                else d = (d + 1) % 4;
                if (!flag[x][y]) cnt++, flag[x][y] = 1;
            }
            else if (d == 2) {
                if (y - 1 >= 1 && ch[x][y - 1] == '.') y -= 1;
                else d = (d + 1) % 4;
                if (!flag[x][y]) cnt++, flag[x][y] = 1;
            }
            else if (d == 3) {
                if (x - 1 >= 1 && ch[x - 1][y] == '.') x -= 1;
                else d = (d + 1) % 4;
                if (!flag[x][y]) cnt++, flag[x][y] = 1;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}