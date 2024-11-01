#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char g[1010][1010];
bool f[1010][1010];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof f);
        int n, m, k, x, y, d;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; ++i)
            cin >> (g[i] + 1);
        f[x][y] = 1;
        while (k--)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 1 || ny < 1 || nx > n || ny > m || g[nx][ny] == 'x')
                d = (d + 1) % 4, f[x][y] = 1;
            else
                x = nx, y = ny, f[nx][ny] = 1;
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cnt += f[i][j];
        cout << cnt << endl;
    }
    return 0;
}
