#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1005;
int n, m, k, x, y, dir;
int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool b[MAXN][MAXN];
char a[MAXN][MAXN];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        memset(b, false, sizeof(b));
        cin >> n >> m >> k >> x >> y >> dir;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        b[x][y] = true;
        for (int i = 0; i < k; i++)
        {
            int nx, ny;
            nx = x + d[dir][0], ny = y + d[dir][1];
            if (nx > 0 && nx <= n && ny > 0 && ny <= m && a[nx][ny] != 'x')
            {
                x = nx;
                y = ny;
                b[nx][ny] = true;
            }
            else
                dir = (dir + 1) % 4;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (b[i][j])
                    ans++;
        cout << ans << '\n';
    }
    return 0;
}
