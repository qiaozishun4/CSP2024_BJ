#include <iostream>
#include <cstring>
using namespace std;

const int NR = 1010;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int n, m, k;
int x0, y0, d;
char c[NR][NR];
bool vis[NR][NR];

bool out(int x, int y)
{
    return x <= 0 || x > n || y <= 0 || y > m;
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        memset(c, 0, sizeof(c));
        memset(vis, 0, sizeof(vis));
        cin >> n >> m >> k;
        cin >> x0 >> y0 >> d;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> c[i][j];
        vis[x0][y0] = true;
        int x = x0, y = y0;
        for (int i = 1; i <= k; i++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (out(nx, ny) || c[nx][ny] == 'x') d = (d + 1) % 4;
            else
            {
                vis[nx][ny] = true;
                x = nx, y = ny;
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cnt += vis[i][j];
        cout << cnt << '\n';
    }
    return 0;
}
