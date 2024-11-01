#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int t, n, m, k, x, y, d, vis[1005][1005];
char mp[1005][1005];
int dx[5] = {0, 1, 0, -1};
int dy[5] = {1, 0, -1, 0};

bool check(int x, int y)
{
    if(x < 1 || y < 1 || x > n || y > m || mp[x][y] == 'x')
    {
        return 0;
    }
    return 1;
}

signed main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
    {
        int ans = 0;
        memset(vis, 0, sizeof(vis));
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> mp[i][j];
            }
        }
        for(int i = 1; i <= k; i++)
        {
            // cout << "(" << x << ", " << y << ", d = " << d << ")\n";
            if(!vis[x][y])
            {
                // cout << "   ans++\n";
                vis[x][y] = 1;
                ans++;
            }
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(!check(nx, ny))
            {
                d++;
                d %= 4;
                // cout << "   (" << x << ", " << y << ", d = " << d << ")\n";
                continue;
            }
            x = nx;
            y = ny;
            // cout << "   (" << x << ", " << y << ", d = " << d << ")\n";
        }
        if(!vis[x][y])
        {
            // cout << "   ans++\n";
            vis[x][y] = 1;
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}