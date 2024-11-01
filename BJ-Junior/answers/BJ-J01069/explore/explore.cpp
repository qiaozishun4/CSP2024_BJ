#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int T, n, m, k, x, y, d, cnt, vis[N][N];
char mp[N][N];
bool chk(int i, int j) {
    return (i <= n && j <= m && i >= 1 && j >= 1);
}
void dfs(int xx, int yy, int d1, int st) {
    if (st > k) return;
    if (!vis[xx][yy]) cnt ++;
    vis[xx][yy] = 1;
    if (d1 == 0) {
        if (chk(xx, yy + 1) && mp[xx][yy + 1] == '.') dfs(xx, yy + 1, d1, st + 1);
        else dfs(xx, yy, (d1 + 1) % 4, st + 1);
    } else if (d1 == 1) {
        if (chk(xx + 1, yy) && mp[xx + 1][yy] == '.') dfs(xx + 1, yy, d1, st + 1);
        else dfs(xx, yy, (d1 + 1) % 4, st + 1);
    } else if (d1 == 2) {
        if (chk(xx, yy - 1) && mp[xx][yy - 1] == '.') dfs(xx, yy - 1, d1, st + 1);
        else dfs(xx, yy, (d1 + 1) % 4, st + 1);
    } else if (d1 == 3) {
        if (chk(xx - 1, yy) && mp[xx - 1][yy] == '.') dfs(xx - 1, yy, d1, st + 1);
        else dfs(xx, yy, (d1 + 1) % 4, st + 1);
    }

}
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
    cin >> T;
    while (T --) {
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++) cin >> mp[i][j];
        cnt = 0;
        memset(vis, 0, sizeof vis);
        dfs(x, y, d, 0);
        cout << cnt << '\n';
    }
    return 0;
}
