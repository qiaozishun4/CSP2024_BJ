#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 1e3 + 5;

char a[N][N];
bool vis[N][N];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m, k;

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(vis, false, sizeof(vis));
        scanf("%d%d%d", &n, &m, &k);
        k++;
        int x, y, d;
        scanf("%d%d%d", &x, &y, &d);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        while (k--)
        {
            vis[x][y] = true;
            int x_n = x + dx[d], y_n = y + dy[d];
            if (x_n < 1 || x_n > n || y_n < 1 || y_n > m || a[x_n][y_n] == 'x')
            {
                d = (d + 1) % 4;
                continue;
            }
            x = x_n;
            y = y_n;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (vis[i][j]) cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
