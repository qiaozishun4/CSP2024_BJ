#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool vis[1005][1005];
void move(int &x, int &y, int &d)
{
    char next;
    int x1, y1;
    if (d == 0)
    {
        x1 = x;
        y1 = y+1;
    }
    else if (d == 1)
    {
        x1 = x+1;
        y1 = y;
    }
    else if (d == 2)
    {
        x1 = x;
        y1 = y-1;
    }
    else
    {
        x1 = x-1;
        y1 = y;
    }
    next = a[x1][y1];
    if (next == '\0' || next == 'x')
    {
        d++;
        d %= 4;
    }
    else
    {
        x = x1;
        y = y1;
        vis[x][y] = 1;
    }
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int ans = 0, n, m, k, x, y, d;
        memset(vis, 0, sizeof(vis));
        memset(a, '\0', sizeof(a));
        cin >> n >> m >> k >> x >> y >> d;
        vis[x][y] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        while (k--)
            move(x, y, d);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (vis[i][j])
                    ans++;
        cout << ans << '\n';
    }
    return 0;
}
