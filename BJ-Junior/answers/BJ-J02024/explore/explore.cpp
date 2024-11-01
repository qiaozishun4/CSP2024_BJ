#include <bits/stdc++.h>
using namespace std;
bool a[1001][1001];
bool b[1001][1001];
int t, d, n, m, k, x, y, suminT;
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.in", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        suminT = 0;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int j = 1; j <= 1000; j++)
        {
            for (int k = 1; k <= 1000; k++)
            {
                a[j][k] = 1;
                b[j][k] = 0;
            }
        }
        b[x][y] = 1;
        for (int j = 1; j <= n; j++)
        {
            string mm;
            cin >> mm;
            for (int l = 1; l <= m; l++)
            {
                if (mm[l - 1] == '.')
                {
                    a[j][l] = 0;
                }
            }
        }
        while (k > 0)
        {
            k--;
            if (d == 0 && !a[x][y + 1])
            {
                y += 1;
                b[x][y] = 1;
            }
            else if (d == 1 && !a[x + 1][y])
            {
                x += 1;
                b[x][y] = 1;
            }
            else if (d == 2 && !a[x][y - 1] && y != 1)
            {
                y -= 1;
                b[x][y] = 1;
            }
            else if (d == 3 && !a[x - 1][y] && x != 1)
            {
                x -= 1;
                b[x][y] = 1;
            }
            else if (d == 0 && a[x][y + 1])
            {
                d = 1;
            }
            else if (d == 1 && a[x + 1][y])
            {
                d = 2;
            }
            else if ((d == 2 && a[x][y - 1]) || (d == 2 && y == 1))
            {
                d = 3;
            }
            else if ((d == 3 && a[x - 1][y]) || (d == 3 && x == 1))
            {
                d = 0;
            }
        }
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                if (b[j][k])
                {
                    suminT++;
                }
            }
        }
        cout << suminT << endl;
    }
    return 0;
}
