#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, k, x, y, d;
        cin >> n >> m >> k >> x >> y >> d;
        bool a[n + 1][m + 1], b[n + 1][m + 1];
        memset(b, false, sizeof(b));
        b[x][y] = true;
        char c;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> c;
                if(c == '.')
                {
                    a[i][j] = true;
                }
                else
                {
                    a[i][j] = false;
                }
            }
        }
        while(k--)
        {
            if(d == 0)
            {
                if(y + 1 <= m && a[x][y + 1])
                {
                    y++;
                }
                else
                {
                    d++;
                    d %= 4;
                }
            }
            else if(d == 1)
            {
                if(x + 1 <= n && a[x + 1][y])
                {
                    x++;
                }
                else
                {
                    d++;
                    d %= 4;
                }
            }
            else if(d == 2)
            {
                if(y - 1 >= 1 && a[x][y - 1])
                {
                    y--;
                }
                else
                {
                    d++;
                    d %= 4;
                }
            }
            else
            {
                if(x - 1 >= 1 && a[x - 1][y])
                {
                    x--;
                }
                else
                {
                    d++;
                    d %= 4;
                }
            }
            b[x][y] = true;
        }
        int num = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(b[i][j])
                {
                    num++;
                }
            }
        }
        cout << num << endl;
    }
    return 0;
}
