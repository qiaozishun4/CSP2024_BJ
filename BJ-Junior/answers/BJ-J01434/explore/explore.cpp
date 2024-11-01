#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    long long t;
    cin >> t;
    while(t--)
    {
        long long n, m, k, x, y, d, go = 1;
        cin >> n >> m >> k >> x >> y >> d;
        char map[1005][1005];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> map[i][j];
            }
        }
        while(k--)
        {
            bool flag = 0;
            if (d == 0)
            {
                if (map[x][y+1] == '.')
                {
                    y++;
                    flag = 1;
                }
            }
            else if (d == 1)
            {
                if (map[x+1][y] == '.')
                {
                    x++;
                    flag = 1;
                }
            }
            else if (d == 2)
            {
                if (map[x][y-1] == '.')
                {
                    y--;
                    flag = 1;
                }
            }
            else if (d == 3)
            {
                if (map[x-1][y] == '.')
                {
                    x--;
                    flag = 1;
                }
            }

            if (flag)
            {
                go++;
            }
            else
            {
                d = (d + 1) % 4;
            }
        }
        cout << go << '\n';
    }
    return 0;
}
