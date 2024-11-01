#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1e3 + 10;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int t;
bool inbound(int x, int y, int n, int m) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while (t--) {
        int n, m, k, ans = 0;
        bool visit[maxn][maxn];
        char s[maxn][maxn];
        int x, y, d;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        visit[x][y] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> s[i][j];
        while (k--) {
            int i = x + dx[d];
            int j = y + dy[d];
            if (inbound(i, j, n, m) && s[i][j] == '.') {
                x = i;
                y = j;
                visit[i][j] = true;
            }
            else d = (d + 1) % 4;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (visit[i][j]) {
                    ans++;
                }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                visit[i][j] = false;
        cout << ans << '\n';
    }
    return 0;
}
