#include <iostream>
#include <cstdio>
using namespace std;

int dx[5] = {0, 1, 0, -1}, dy[5] = {1, 0, -1, 0};
char a[1005][1005];
bool f[1005][1005];

bool in(int n, int m, int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k, x, y, d;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                f[i][j] = 0;
        f[x][y] = 1;
        while (k--)
        {
            int mx = x + dx[d], my = y + dy[d];
            if (in(n, m, mx, my) && a[mx][my] != 'x')
            {
                x = mx;
                y = my;
                f[x][y] = 1;
            }
            else d = (d + 1) % 4;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (f[i][j]) cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
