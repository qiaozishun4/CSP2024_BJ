#include <iostream>
using namespace std;

void explore()
{
    char a[1010][1010];
    bool flag[1010][1010];
    memset(flag, false, sizeof(flag));
    int n, m, k, x, y, d;
    cin >> n >> m >> k >> x >> y >> d;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= k; i++)
    {
        flag[x][y] = true;
        int x1 = x, y1 = y;
        if (d == 0) y1++;
        else if (d == 1) x1++;
        else if (d == 2) y1--;
        else x1--;
        if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && a[x1][y1] == ".")
        {
            x = x1;
            y = y1;
            
        }
        else
        {
            d = (d+1) % 4;
        }
    }
    flag[x][y] = true;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (flag[i][j]) cnt++;
        }
    }
    cout << cnt << endl;
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        explore();
    }
    return 0;
}