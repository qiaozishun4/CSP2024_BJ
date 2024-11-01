#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

#define int long long

void Main()
{
    int n,m,k;
    cin >> n >> m >> k;
    char m1[1005][1005] = {};
    int x0,y0,d0;
    cin >> x0 >> y0 >> d0;
    for (int i = 1;i <= n;i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 1;j <= m;j++)
        {
            m1[i][j] = tmp[j - 1];
        }
    }
    m1[x0][y0] = 'v';
    for (int i = 1;i <= k;i++)
    {
        int x,y;
        if (d0 == 0)
        {
            x = x0;
            y = y0 + 1;
        }
        else if (d0 == 1)
        {
            x = x0 + 1;
            y = y0;
        }
        else if (d0 == 2)
        {
            x = x0;
            y = y0 - 1;
        }
        else if (d0 == 3)
        {
            x = x0 - 1;
            y = y0;
        }
        if (x >= 1 && x <= n && y >= 1 && y <= m && m1[x][y] != 'x')
        {
            x0 = x;
            y0 = y;
            m1[x0][y0] = 'v';
        }
        else
        {
            d0 = (d0 + 1) % 4;
        }
    }
    int cnt = 0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            if (m1[i][j] == 'v')
            {

                cnt++;
            }
        }
    }
    cout << cnt << endl;
}

signed main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    for (int i = 1;i <= T;i++)
    {
        Main();
    }
    return 0;
}
