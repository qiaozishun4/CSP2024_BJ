#include <iostream>
#include <cstring>
using namespace std;

char c[1005][1005];
bool f[1005][1005];

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k, x, y, d, cnt = 0;
        cin >> n >> m >> k >> x >> y >> d;
        memset(f, false, sizeof f);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> c[i][j];
        for (int i = 1; i <= k; i++)
        {
            f[x][y] = true;
            if (d == 0 && y + 1 <= m && c[x][y + 1] == '.')  y++;
            else if (d == 1 && x + 1 <= n && c[x + 1][y] == '.')  x++;
            else if (d == 2 && y - 1 >= 1 && c[x][y - 1] == '.')  y--;
            else if (d == 3 && x - 1 >= 1 && c[x - 1][y] == '.')  x--;
            else  d = (d + 1) % 4;
        }
        f[x][y] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (f[i][j])  cnt++;
        cout << cnt << endl;
    }
    return 0;
}
