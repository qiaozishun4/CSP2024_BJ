#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 5;
const int mod = 4;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
ll ans;
int n, m, k;
int xc, yc, d;
int mp[N][N];

void dfs(int x, int y, int step, int d) {
    if(step == k + 1) return;
    int nx = x + dx[d], ny = y + dy[d];
    if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] != 1) {
        mp[nx][ny] = 2;
        // cout << nx << ' ' << ny << '\n';
        dfs(nx, ny, step + 1, d);
    } else {
        // cout << x << ' ' << y << '\n';
        dfs(x, y, step + 1, (d + 1) % mod);
    }
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        cin >> xc >> yc >> d;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                mp[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                char x; cin >> x;
                if(x == 'x') mp[i][j] = 1;
            }
        }
        mp[xc][yc] = 2;
        dfs(xc, yc, 0, d);
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(mp[i][j] == 2) ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
