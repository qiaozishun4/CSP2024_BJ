#include <iostream>
using namespace std;

const int N = 1000;
const int dx[4]{0, 1,  0, -1};
const int dy[4]{1, 0, -1,  0};

struct Node
{
    int x, y, d;
};

bool vis[N + 5][N + 5];
char g[N + 5][N + 5];

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k; Node u;
        cin >> n >> m >> k >> u.x >> u.y >> u.d;
        for (int i = 1; i <= n; ++i) g[i][0] = g[i][m + 1] = 'x';
        for (int i = 1; i <= m; ++i) g[0][i] = g[n + 1][i] = 'x';
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cin >> g[i][j];
                vis[i][j] = false;
            }
        }

        vis[u.x][u.y] = true;
        while (k--)
        {
            Node v{u.x + dx[u.d], u.y + dy[u.d], u.d};
            if (g[v.x][v.y] != 'x') u = v;
            else u.d = (u.d + 1) % 4;
            vis[u.x][u.y] = true;
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (vis[i][j])
                    ++ans;
        cout << ans << endl;
    }

    return 0;
}