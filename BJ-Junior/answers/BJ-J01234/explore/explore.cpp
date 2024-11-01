#include <bits/stdc++.h>
using namespace std;

int T, n, m, k, xc, yc, dc;
char c[1005][1005];
bool bl[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    for (int i = 0; i <= 1004; i++)
    {
        c[0][i] = 'x';
        c[i][0] = 'x';
    }
    while (T--)
    {
        memset(bl, 0, sizeof(bl));//
        cin >> n >> m >> k;
        cin >> xc >> yc >> dc;
        int x = xc, y = yc, d = dc;
        for (int i = 0; i <= n + 1; i++) c[i][m + 1] = 'x';
        for (int i = 0; i <= m + 1; i++) c[n + 1][i] = 'x';
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> c[i][j];
            }
        }
        int cnt = 1;
        bl[xc][yc] = 1;
        bool f = 0;
        for (int i = 0; i <= 3; i++)
        {
            if (c[xc + dx[i]][yc + dy[i]] == '.')
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            cout << "1" << endl;
            continue;
        }
        while (k != 0)
        {
            k--;
            if (c[x + dx[d]][y + dy[d]] == '.')
            {
                x += dx[d];
                y += dy[d];
                //cout << x << " " << y << endl;
                if (!bl[x][y])
                {
                    bl[x][y] = 1;
                    cnt++;
                }
            }
            else d = (d + 1) % 4;
        }
        cout << cnt << endl;
    }

    return 0;
}