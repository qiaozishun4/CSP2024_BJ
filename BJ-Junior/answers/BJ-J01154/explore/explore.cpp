#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int t, n, m, k;
char a[1010][1010];
int vis[1010][1010];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                vis[i][j] = 0;
            }
        vis[x][y] = 1;
        int ans = 1;
        for (int i = 1; i <= k; i++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            bool flag = true;
            if (nx < 1 || nx > n)
                flag = false;
            if (ny < 1 || ny > m)
                flag = false;
            if (a[nx][ny] == 'x')
                flag = false;
            if (flag)
            {
                x = nx;
                y = ny;
                if (!vis[x][y])
                    ans++;
                vis[x][y] = 1;
            }
            else d = (d + 1) % 4;
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
