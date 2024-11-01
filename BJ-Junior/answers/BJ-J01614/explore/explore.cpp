#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int cnt = 1;
        int x, y, d;
        cin >> x >> y >> d;
        --x;
        --y;
        char a[n][m];
        for(int j = 0; j < n; ++j)
        {
            for(int l = 0; k < m; ++k)
            {
                cin >> a[j][l];
            }
        }
        for(int j = 0; j < k; ++j)
        {
            if(d == 0)
            {
                if(y + 1 > n || a[x][y + 1] == 'x')
                {
                    d = 1;
                    continue;
                }
                y += 1;
                ++cnt;
                continue;
            }
            if(d == 1)
            {
                if(x + 1 > m || a[x + 1][y] == 'x')
                {
                    d = 2;
                    continue;
                }
                x += 1;
                ++cnt;
                continue;
            }
            if(d == 2)
            {
                if(y - 1 < 0 || a[x][y - 1] == 'x')
                {
                    d = 3;
                    continue;
                }
                y -= 1;
                ++cnt;
                continue;
            }
            if(x - 1 < 0 || a[x - 1][y] == 'x')
            {
                d = 0;
                continue;
            }
            ++cnt;
            x -= 1;
        }
        cout << cnt;
        cout << endl;
    }
}