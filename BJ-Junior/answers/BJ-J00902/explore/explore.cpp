#include <iostream>
using namespace std;

char c[1050][1050];

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n, m, k, y, x, d;
        cin >> n >> m >> k >> y >> x >> d;
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                cin >> c[j][k];
            }
        }
        int cnt = 1;
        c[y][x] = '#';
        while (k > 0)
        {
            if (d == 0)
            {
                if (x + 1 > m || c[y][x + 1] == 'x')
                {
                    d++;
                }
                else
                {
                    x++;
                }
            }
            else if (d == 1)
            {
                if (y + 1 > n || c[y + 1][x] == 'x')
                {
                    d++;
                }
                else
                {
                    y++;
                }
            }
            else if (d == 2)
            {
                if (x - 1 < 1 || c[y][x - 1] == 'x')
                {
                    d++;
                }
                else
                {
                    x--;
                }
            }
            else
            {
                if (y - 1 < 1 || c[y - 1][x] == 'x')
                {
                    d = 0;
                }
                else
                {
                    y--;
                }
            }
            if (c[y][x] != '#')
            {
                c[y][x] = '#';
                cnt++;
            }
            k--;
        }
        cout << cnt << endl;
    }
    return 0;
}
