#include <bits/stdc++.h>
using namespace std;
#define int long long

int vis[1010][1010];
char c[1010][1010];
signed main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> c[i][j];
                vis[i][j] = 0;
            }
        }
        vis[x][y] = 1;
        for(int i = 1; i <= k; i++)
        {
            int nx, ny, nd = (d + 1) % 4;
            if(d == 0)
            {
                nx = x;
                ny = y + 1;
            }
            else if(d == 1)
            {
                nx = x + 1;
                ny = y;
            }
            else if(d == 2)
            {
                nx = x;
                ny = y - 1;
            }
            else
            {
                nx = x - 1;
                ny = y;
            }
            if(nx < 1 || nx > n || ny < 1 || ny > m || c[nx][ny] == 'x')
                d = nd;
            else
            {
                x = nx;
                y = ny;
                vis[nx][ny] = 1;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                ans += vis[i][j];
        }
        cout << ans << endl;
    }
    return 0;
}
