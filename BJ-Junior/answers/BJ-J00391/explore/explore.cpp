#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t, n, m, k, x, y, d, sum;
    char c[1005][1005];
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> m >> k >> x >> y >> d;
        sum = 1;
        for (int j = 1; j <= n; j++)
        {
            for (int g = 1; g <= m; g++)
            {
                cin >> c[j][g];
            }
        }
	for (int j = 1; j <= k; j++)
        {
            if (d == 0)
            {
                if (y + 1 <= m && c[x][y + 1] == '.')
                {
                    y += 1;
                    sum++;
                }
                else
                {
                    d = (d + 1) % 4;
                    continue;
                }
            }
            else if (d == 1)
            {
                if (x + 1 <= n && c[x + 1][y] == '.')
                {
                    x += 1;
                    sum++;
                }
                else
                {
                    d = (d + 1) % 4;
                    continue;
                }
            }
            else if (d == 2)
            {
                if (y - 1 >= 1 && c[x][y - 1] == '.')
                {
                    y -= 1;
                    sum++;
                }
                else
                {
                    d = (d + 1) % 4;
                    continue;
                }
            }
            else if (d == 3)
            {
                if (x - 1 >= 1 && c[x - 1][y] == '.')
                {
                    x -= 1;
                    sum++;
                }
                else
                {
                    d = (d + 1) % 4;
                    continue;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}