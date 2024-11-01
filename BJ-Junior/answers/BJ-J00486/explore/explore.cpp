#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1010;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int t, n, m, k, d, stx, sty;
char a[maxn][maxn];
bool vis[maxn][maxn];
bool inb(int x, int y) { return x > 0 && y > 0 && x <= n && y <= m; }
#undef int
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    #define int long long
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        memset(vis, false, sizeof(vis));
        cin >> n >> m >> k;
        cin >> stx >> sty >> d;
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++) cin >> a[i][j];
        vis[stx][sty] = true;
        int x = stx, y = sty, ans = 0;
        while (k--) {
            int nx = x + dx[d], ny = y + dy[d];
            if (inb(nx, ny) && a[nx][ny] == '.') x = nx, y = ny, vis[x][y] = true;
            else d = (d + 1) % 4;
        }
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++) ans += vis[i][j];
        cout << ans << "\n";
    } 
    return 0;
}