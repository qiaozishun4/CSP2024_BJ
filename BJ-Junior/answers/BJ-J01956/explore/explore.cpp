#include<bits/stdc++.h>
using namespace std;
char M[1005][1005];
bool vis[1005][1005];

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        memset(M, 0, sizeof(M));
        memset(vis, 0, sizeof(vis));
        int n, m, k;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        int cnt = 0;
        vis[x][y] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> M[i][j];
            }
        }
        for (int i = 1 ;i <= k; i++)
        {
            if (d == 0)
            {
                if (y + 1 >= 1 && y + 1 <= m && M[x][y + 1] == '.')
                {
                    y++;
                    vis[x][y] = 1;
                }
                else
                    d = (d + 1) % 4;
            }
            else if (d == 1)
            {
                if (x + 1 >= 1 && x + 1 <= n && M[x + 1][y] == '.')
                {
                    x++;
                    vis[x][y] = 1;
                }
                else
                    d = (d + 1) % 4;
            }
            else if (d == 2)
            {
                if (y - 1 >= 1 && y - 1 <= m && M[x][y - 1] == '.')
                {
                    y--;
                    vis[x][y] = 1;
                }
                else
                    d = (d + 1) % 4;
            }
            else
            {
                if (x -  1 >= 1 && x - 1 <= n && M[x - 1][y] == '.')
                {
                    x--;
                    vis[x][y] = 1;
                }
                else
                    d = (d + 1) % 4;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (vis[i][j] == 1) cnt++;
            }
        }
        cout << cnt << endl;
    }
}
