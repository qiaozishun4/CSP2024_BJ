#pragma GCCoptimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
char b[1005][1005];
int t, k, n, m, x, y, d;
int ans[1005][1005];
using namespace std;
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int z = 1 ; z <= t ; z++)
    {
        memset(b, 0, sizeof(b));
        memset(ans, 0, sizeof(ans));
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = 1 ; j <= m ; j++)
            {
                cin >> b[i][j];
            }
        }
        for (int i = 1 ; i <= k ; i++)
        {
            ans[x][y] = 1;
            if ((d == 0 && (b[x][y+1] != '.')) || (d == 1 && (b[x+1][y] != '.')) || (d == 2 && (b[x][y-1] != '.')) || (d == 3 && (b[x-1][y] != '.')))
            {
                d = (d+1)%4;
            }
            else
            {
                if (d == 0)
                {
                    y++;
                }
                else if (d == 1)
                {
                    x++;
                }
                else if (d == 2)
                {
                    y--;
                }
                else
                {
                    x--;
                }
            }
            ans[x][y] = 1;
        }
        int tot = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = 1 ; j <= m ; j++)
            {
                tot+=ans[i][j];
            }
        }
        cout << tot << "\n";
    }
    cout << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
