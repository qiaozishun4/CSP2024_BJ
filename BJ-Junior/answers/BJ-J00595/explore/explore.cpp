#include <bits/stdc++.h>
using namespace std;
int n, m, k, d, x, y, x_, y_, t;
int main()
{
    freopen("explore5.in", "r", stdin);
    freopen("explore5.out", "w", stdout);
    cin >> t;
    while (t != 0)
    {
        long long num = 0;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        char a[n + 1][m + 1];
        int b[n + 1][m + 1];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                b[i][j] = 0;
            }
        }
        for (int i = 1; i <= k; i++)
        {
            b[x][y]++;
            if (d == 0)
            {
                x_ = x;
                y_ = y + 1;
            }
            else if (d == 1)
            {
                x_ = x + 1;
                y_ = y;
            }
            else if (d == 2)
            {
                x_ = x;
                y_ = y - 1;
            }
            else if (d == 3)
            {
                x_ = x - 1;
                y_ = y;
            }
            if (x_ < 1 || x_ > n || y_ < 1 || y_ > m || a[x_][y_] == 'x')
            {
                if (d == 3)
                {
                    d = 0;
                }
                else
                {
                    d++;
                }
            }
            else
            {
                x = x_;
                y = y_;
            }
            b[x][y]++;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (b[i][j] != 0)
                {
                    num++;
                }
            }
        }
        cout << num << endl;
        t--;
    }
}
