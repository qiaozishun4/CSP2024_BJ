#include <iostream>
using namespace std;

char p[1005][1005];

int n, m, k, x, y, d;

int ans(int t, int cnt)
{
    t++;
    int cnt = 0;
    if (t == k) return cnt;
    
    if (d == 0 && p[x][y + 1] !=' x')
    {
        cnt++;
        y++;
        return ans(t, cnt);
    }
    else if (d == 1 && p[x + 1][y] !=' x')
    {
        cnt++;
        x++;
        return ans(t, cnt)
    }
    else if (d == 2 && p[x][y - 1] !=' x')
    {
        cnt++;
        y--;
        return ans(t, cnt);
    }
    else if (d == 3 && p[x - 1][y] !=' x')
    {
        cnt++;
        x--;
        return ans(t, cnt);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(p, 'x', sizeof p);
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cin >> p[i][j];
        cout << ans(0, 0)
    }
    return 0;
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        memset(p, 'x', sizeof p);
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cin >> p[i][j];
            }
        }
        cout << ans();
    }
    return 0;
}
