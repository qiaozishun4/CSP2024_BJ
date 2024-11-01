#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 7, maxm = 1e3 + 7;
int t, n, m, d, k, x, y;
char a[maxn][maxm];
short dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool flag[maxn][maxm];
void p(int &x, int &y) {
    int x_ = x + dx[d], y_ = y + dy[d];
    if(1 <= x_ && x_ <= n && 1 <= y_ && y_ <= m && a[x_][y_] == '.')
        x = x_, y = y_;
    else
        d = (d + 1) % 4;
    flag[x][y] = true;
    return;
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        memset(flag, false, sizeof(flag));
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++)
                cin >> a[i][j];
        }
        flag[x][y] = true;
        for(int i = 1; i <= k; i ++)
            p(x, y);
        int ans = 0;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++)
                if(flag[i][j])
                    ans++;
        }
        cout << ans << endl;
    }
    return 0;
}