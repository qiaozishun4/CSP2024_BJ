#include<iostream>
#include<string.h>
using namespace std;
int t;
string map[1010];
int cnt[1010][1010];
int n, m, k, x, y, d;
void dfs(int x, int y, int d, int step) {
    cnt[x][y] = 1;
    if (step == k) {
        return;
    }
    int tx, ty;
    if (d == 0) {
        tx = x;
        ty = y + 1;
    }
    else if (d == 1) {
        tx = x + 1;
        ty = y;
    }
    else if (d == 2) {
        tx = x;
        ty = y - 1;
    }
    else {
        tx = x - 1;
        ty = y;
    }
    if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && map[tx][ty] != 'x') {
        dfs(tx, ty, d, step + 1);
    }
    else {
        dfs(x, y, (d + 1) % 4, step + 1);
    }
}
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while (t--) {
        int ans = 0;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++) {
            cin >> map[i];
            map[i].insert(0, " ");
        }
        dfs(x, y, d, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (cnt[i][j]) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
        memset(cnt, 0, sizeof cnt);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
