#include<bits/stdc++.h>
using namespace std;
int T;
const int maxn = 1e3+5;
const int maxm = 1e3+5;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

char s[maxn][maxm];
bool vis[maxn][maxm];

int ans;

void dfs(int x, int y, int d, int n, int m, int k, int curstep) {
    if (curstep > k) return;
    vis[x][y] = 1;
    curstep++;
    bool flag = (x+dx[d] <= 0 || x+dx[d] > n || y+dy[d] <= 0 || y+dy[d] > m || s[x+dx[d]][y+dy[d]] == 'x');
    if (!flag) {
        dfs(x+dx[d], y+dy[d], d, n, m, k, curstep);
    }
    else {
        int dd = (d+1)%4;
        dfs(x, y, dd, n, m, k, curstep);
    }
}

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        int xs, ys, d;
        cin >> xs >> ys >> d;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> s[i][j];
            }
        }
        dfs(xs, ys, d, n, m, k, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (vis[i][j]) ans++;
            }
        }
        cout << ans << "\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                s[i][j] = ' ';
            }
        }
        ans = 0;
    }
    return 0;
}
