#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, x, y, d, ans;
const int xx[4] = {0, 1, 0, -1}, yy[4] = {1, 0, -1, 0};
char a[1005][1005];
bool f[1005][1005];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        memset(a, 0, sizeof(a));
        ans = 0;
        cin >> n >> m >> k >> x >> y >> d;
        f[x][y] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        for (int i = 1; i <= k; i++)
        {
            int fx = x, fy = y;
            fx += xx[d], fy += yy[d];
            if (fx < 1 || fy < 1 || fx > n || fy > m || a[fx][fy] == 'x') {d = (d + 1) % 4; continue;}
            x = fx, y = fy;
            f[x][y] = 1;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (f[i][j])
                    ans++;
        cout << ans << endl;
    }
}
