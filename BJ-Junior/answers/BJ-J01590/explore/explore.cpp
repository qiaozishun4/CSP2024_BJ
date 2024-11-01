#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool vis[1005][1005];
bool check(int n, int m, int x, int y) {
    return (x < n && y < m && a[x][y] == '.' && !vis[x][y]);
}
void dfs(int n, int m, int x, int y, int d, int k, int ans) {
    if (k == 0) {
        cout << ans << endl;
    }

    vis[x][y] == true;
    for (int i = 0; i < 4; i++) {
        if (d == 0 && check(n, m, x, y + 1)) {
            //dfs(n, m, x, y + 1, d, k - 1, ans + 1);
            cout << 2 << endl;
            return ;
        } else if (d == 1 && check(n, m, x + 1, y)) {
            //dfs(n, m, x + 1, y, d, k - 1, ans + 1);
            cout << 2 << endl;
            return ;
        } else if (d == 2 && check(n, m, x, y - 1)) {
            //dfs(n, m, x, y - 1, d, k - 1, ans + 1);
            cout << 2 << endl;
            return ;
        } else if (d == 3 && check(n, n, x - 1, y)) {
            //dfs(n, m, x - 1, y, d, k - 1, ans + 1);
            cout << 2 << endl;
            return ;
        }
        //printf(">>>%d", d);
        d = (d + 1) % 4;//<-问题出现
    }
    cout << ans << endl;
    return ;
}
int main() {
    freopen ("explore.in", "r", stdin);
    freopen ("explore.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x, y, d;
        cin >> n >> m >> k >> x >> y >> d;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        dfs(n, m, x, y, d, k, 1);
        cout << endl;
    }
    return 0;
}