#include <bits/stdc++.h>
using namespace std;
char s[1005][1005];
bool b[1005][1005];
int T, n, m, k, x, y, d, cnt = 0;
int dx[10] = {0, 1, 0, -1}, dy[10] = {1, 0, -1, 0};
bool In(int x_, int y_)
{
    return 1 <= x_ && 1 <= y_ && x_ <= n && y_ <= m && s[x_][y_] == '.';
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        cnt = 1;
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> s[i][j];
        for (int i = 1; i <= k; i++)
        {
            int ex = x + dx[d], ey = y + dy[d];
            if (In(ex, ey))
            {
                x = ex, y = ey;
                if (!b[x][y]) cnt ++, b[x][y] = true;
            }
            else
                d = (d+1) % 4;
        }
        cout <<cnt <<endl;
    }
    return 0;
}
