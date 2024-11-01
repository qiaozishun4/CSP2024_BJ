#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        char a[1001][1001];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        bool flag[1001][1001];
        flag[x][y] = true;
        for (int i = 1; i <= k; i++)
        {
            if (d == 0)
            {
                if ((y + 1) <= m && a[x][y + 1] == '.')
                {
                    y++;
                    flag[x][y] = true;
                }
                else
                {
                    d = (d + 1) % 4;
                }
            }
            else if (d == 1)
            {
                if ((x + 1) <= n && a[x + 1][y] == '.')
                {
                    x++;
                    flag[x][y] = true;
                }
                else
                {
                    d = (d + 1) % 4;
                }
            }
            else if (d == 2)
            {
                if (1 <= (y - 1) && a[x][y - 1] == '.')
                {
                    y--;
                    flag[x][y] = true;
                }
                else
                {
                    d = (d + 1) % 4;
                }
            }
            else if (d == 3)
            {
                if (1 <= (x - 1) && a[x - 1][y] == '.')
                {
                    x--;
                    flag[x][y] = true;
                }
                else
                {
                    d = (d + 1) % 4;
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (flag[i][j])
                {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
