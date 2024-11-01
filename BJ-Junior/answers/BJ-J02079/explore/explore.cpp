#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
bool mp[N][N], vis[N][N];
int n, m, k;
int ans;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool judge(int x, int y) {
    if(x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y]) return 1;
    return 0;
}

void dfs(int x, int y, int d, int cnt) {
    //cout << x << " " << y << " " << d << " " << cnt << endl;
    if(cnt == k + 1) return;
    if(judge(x + dir[d][0], y + dir[d][1])) {
        vis[x + dir[d][0]][y + dir[d][1]] = 1;
        //cout << x + dir[d][0] << " " << y + dir[d][1] << endl;
        dfs(x + dir[d][0], y + dir[d][1], d, cnt + 1);
    }
    else {
        dfs(x, y, (d + 1) % 4, cnt + 1);
    }
}

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        memset(mp, 0, sizeof(mp));
        memset(vis, 0, sizeof(vis));
        ans = 0;
        cin >> n >> m >> k;
        int x0, y0, d0;
        cin >> x0 >> y0 >> d0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                char ch;
                cin >> ch;
                if(ch == '.')  mp[i][j] = 1;
            }
        }
        vis[x0][y0] = 1;
        dfs(x0, y0, d0, 1);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(vis[i][j]) {
                    ans++;
                    //cout << i << " " << j << endl;
                }
            }
        }
        cout << ans << endl;
    }
}
