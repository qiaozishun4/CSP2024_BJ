#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, k, x, y, d, X, Y;
char a[1010][1010];
bool vis[1010][1010];

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        memset(vis, false, sizeof(vis));
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        vis[x][y] = true;
        while (k--)
        {
            if (d == 0) X = x, Y = y+1;
            else if (d == 1) X = x+1, Y = y;
            else if (d == 2) X = x, Y = y-1;
            else X = x-1, Y = y;
            if (X < 1 || X > n || Y < 1 || Y > m || a[X][Y] == 'x')
            {
                d = (d+1) % 4;
                continue;
            }
            x = X, y = Y;
            vis[x][y] = true;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (vis[i][j]) cnt++;
        cout << cnt << "\n";
    }
    return 0;
}