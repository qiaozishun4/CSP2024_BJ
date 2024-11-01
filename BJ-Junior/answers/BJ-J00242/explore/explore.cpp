#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
ll t, n, m, k, x, y, d, sum = 0;
string a[100000005][100000005];
bool b[100000005][100000005];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> m >> k >> x >> y >> d;
        if (n == 1 && m == 1)
        {
            cout << 1;
            return 0;
        }
        for (int g = 1; g <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[g][j];
            }
        }
        x += 1;
        y += 1;
        while (k--)
        {
            if (d == 0)
            {
                if (a[x][y + 1] == ".")
                {
                    y += 1;
                    b[x][y] = 1;
                    continue;
                }
                else
                {
                    d = 1;
                }
            }
            if (d == 1)
            {
                if (a[x + 1][y] == ".")
                {
                    x += 1;
                    b[x][y] = 1;
                    continue;
                }
                else
                {
                    d = 2;
                }
            }
            if (d == 2)
            {
                if (a[x][y - 1] == ".")
                {
                    y -= 1;
                    b[x][y] = 1;
                    continue;
                }
                else
                {
                    d = 3;
                }
            }
            if (d == 3)
            {
                if (a[x - 1][y] == ".")
                {
                    x -= 1;
                    b[x][y] = 1;
                    continue;
                }
                else
                {
                    d = 0;
                    if (d == 0)
                    {
                        if (a[x][y + 1] == ".")
                        {
                            y += 1;
                            b[x][y] = 1;
                            continue;
                        }
                        else
                        {
                            d = 1;
                        }
                    }
                    else if (d == 1)
                    {
                        if (a[x + 1][y] == ".")
                        {
                            x += 1;
                            b[x][y] = 1;
                            continue;
                        }
                        else
                        {
                            d = 2;
                        }
                    }
                    else if (d == 2)
                    {
                        if (a[x][y - 1] == ".")
                        {
                            y -= 1;
                            b[x][y] = 1;
                            continue;
                        }
                        else
                        {
                            d = 3;
                        }
                    }
                    else if (d == 3)
                    {
                        break;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (b[i][j] == 1)
            {
                sum++;
            }
        }
    }
    cout << sum;
    return 0;
}