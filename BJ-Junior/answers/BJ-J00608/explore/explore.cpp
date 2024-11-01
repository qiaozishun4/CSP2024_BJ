#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


char mp[1005][1005];
bool vis[1005][1005];


int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    int T;
    cin >> T;

    for(int t = 1, n, m, k, x0, y0, d0, ans; t <= T; ++t)
    {
        memset(vis, 0, sizeof vis);
        memset(mp, 'x', sizeof mp);

        cin >> n >> m >> k;
        cin >> x0 >> y0 >> d0;
        vis[x0][y0] = true;

        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                cin >> mp[i][j];
//                vis[i][j] = 0;
            }
        }

        for(int i = 1, x1, y1; i <= k; ++i)
        {
            switch(d0)
            {
            case 0:
                x1 = x0;
                y1 = y0 + 1;
                break;
            case 1:
                x1 = x0 + 1;
                y1 = y0;
                break;
            case 2:
                x1 = x0;
                y1 = y0 - 1;
                break;
            case 3:
                x1 = x0 - 1;
                y1 = y0;
                break;
            }

            if(mp[x1][y1] ==  '.')
            {
                x0 = x1;
                y0 = y1;
            }
            else
            {
                d0 = (d0 + 1) % 4;
            }

            vis[x0][y0] = true;
        }

        ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                if(vis[i][j])
                    ans++;
            }
        }
        cout << ans << endl;
    }
}
