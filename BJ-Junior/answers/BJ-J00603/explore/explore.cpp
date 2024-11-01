#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 +5;
typedef long long ll;
char a[N][N];
bool vis[N][N];
ll t, n, m, k, x, y, d;
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

void read()
{
    memset (vis, 0, sizeof(vis));
    cin >> n >> m >> k;
    cin >> x >> y >> d;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
}

int main()
{
    freopen ("explore.in", "r", stdin);
    freopen ("explore.out", "w", stdout);
    cin >> t;
    while (t --)
    {
        read();
        ll ans = 1;
        vis[x][y] = 1;
        while (k --)
        {
            ll ux = dx[d] + x;
            ll uy = dy[d] + y;
            // cout << ux << " " << uy << " " << d << " " << ans << endl;
            if (ux < 1 || ux > n || uy < 1 || uy > m)
            {
                d = (d + 1) % 4;
                continue;
            }
            if (a[ux][uy] != '.')
            {
                d = (d + 1) % 4;
                continue;
            }
            x = ux, y= uy;
            if (!vis[ux][uy])
               ans ++;
            vis[ux][uy] = 1;
        }
        cout << ans << endl;
    }
    return 0;
}