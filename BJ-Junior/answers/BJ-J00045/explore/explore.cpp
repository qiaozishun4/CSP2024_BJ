#include <bits/stdc++.h>
using namespace std;
char ch[1000+10][1000+10];
bool vis[1000+10][1000+10];
int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        for (int j = 1; j <= n; ++j)
        {
            for (int l = 1; l <= m; ++l)
            {
                cin >> ch[j][l];
            }
        }
        int cnt = 1;
        for (int j = 1; j <= k; ++j)
        {
            int xx = x + pos[d][0];
            int yy = y + pos[d][1];
            if (xx < 1 || xx > n || yy < 1 || yy > m || ch[xx][yy] == 'x')
            {
                d = (d + 1) % 4;
            }
            else
            {
                x = xx;
                y = yy;
                vis[x][y] = 1;
            }
        }
        for (int j = 1; j <= n; ++j)
        {
            for (int l = 1; l <= m; ++l)
            {
                if (vis[j][l] == 1)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
        for (int j = 1; j <= n; ++j)
        {
            for (int l = 1; l <= m; ++l)
            {
                ch[j][l] = '\0';
                vis[j][l] = 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
