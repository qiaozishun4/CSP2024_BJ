#include <bits/stdc++.h>
using namespace std;

char ex[1005][1005];
bool ex2[1005][1005];

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    int cnt = 1;
    while(T--)
    {
        int n, m, k;
        int x, y, d;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        memset(ex, false,sizeof(ex));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cin >>ex[i][j];
            }
        }
        while (k--)
        {
            if (d == 0)
            {
                if (ex[x][y + 1] == '.' && 0 < x && x <= n && 0 < y+1 && y+1 <= m)
                {
                    y++;
                }
                else
                {
                    d = (d + 1) % 4;
                    continue;
                }
            }
            if (d == 1)
            {
                if (ex[x+1][y] == '.' && 0 < x+1 && x+1 <= n && 0 < y && y <= m)
                {
                    x++;
                }
                else
                {
                    d = (d + 1) % 4;
                    continue;
                }
            }
            if (d == 2)
            {
                if (ex[x][y - 1] == '.' && 0 < x && x <= n && 0 < y-1 && y-1 <= m)
                {
                    y--;
                }
                else
                {
                    d = (d + 1) % 4;
                    continue;
                }
            }
            if (d == 3)
            {
                if (ex[x - 1][y] == '.' && 0 < x-1 && x-1 <= n && 0 < y && y <= m)
                {
                    x--;
                }
                else
                {
                    d = (d + 1) % 4;
                    continue;
                }
            }
            ex2[x][y] = true;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (ex2[i][j] == true) cnt++;
            }
        }
        cout << cnt << endl;
        cnt = 1;
    }
    return 0;
}