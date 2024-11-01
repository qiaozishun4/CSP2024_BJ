#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 10;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

char sand[maxn][maxn];
bool vis[maxn][maxn];
int n, m, k, cnt, t, d, x, y;

bool inb(int u, int v)
{
    return u > 0 && u <= n && v > 0 && v <= m;
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    cin >> t;

    while (t--)
    {
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> sand[i][j];

        memset(vis, 0, sizeof vis);
        vis[x][y] = 1;

        while (k--)
        {
            int nx = x + dx[d], ny = y + dy[d];

            if (inb(nx, ny) && sand[nx][ny] != 'x')
            {
                x = nx;
                y = ny;
                vis[x][y] = 1;
            }
            else d = (d + 1) % 4;
        }

        cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (vis[i][j])
                    cnt++;
        cout << cnt << endl;
    }

    return 0;
}
