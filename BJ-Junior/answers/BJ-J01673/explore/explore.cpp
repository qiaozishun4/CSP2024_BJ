#include <bits/stdc++.h>
using namespace std;
bool flag[10001][10001], pass[10001][10001];
int t = 0, n = 0, m = 0, k = 0, ax[] = {0, 1, 0, -1}, ay[] = {1, 0, -1, 0};
void dfs(int x, int y, int d) {
    pass[x][y] = 1;
    if (--k == -1) return;
    if (flag[x + ax[d]][y + ay[d]]) dfs(x + ax[d], y + ay[d], d);
    else dfs(x, y, (d + 1) % 4);
}
int main() {
    freopen("explore5.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while (t--) {
        int x = 0, y = 0, d = 0, ans = 0;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                pass[i][j] = flag[i][j] = 0;
                char c = ' ';
                cin >> c;
                if (c == '.') flag[i][j] = 1;
            }
        dfs(x, y, d);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (pass[i][j]) ++ans;
        cout << ans << endl;
    }
    return 0;
}