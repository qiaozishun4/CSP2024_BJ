# include <iostream>
# include <cstring>
using namespace std;

char a[1005][1005];
bool vis[1005][1005];
long long g[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
long long n, m, k;
long long cnt;
void solve(long long x, long long y, long long sd, long long sk)
{
    if (vis[x][y] == false) cnt++;
    vis[x][y] = true;
    if (sk == k)
    {
        cout << cnt << endl;
        return;
    }
    long long nx = x + g[sd][0];
    long long ny = y + g[sd][1];

    if (nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == 'x')
    {
        solve(x, y, (sd + 1) % 4, sk + 1);
    }
    else
    {
        solve(nx, ny, sd, sk + 1);
    }
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    long long T;
    long long x, y, d;
    cin >> T;
    while (T--)
    {

        cin >> n >> m >> k;
        cin >> x >> y >> d;
        memset(vis, false, sizeof(vis));
        for (long long i = 1; i <= n; i ++)
        {
            for (long long j = 1; j <= m; j ++)
            {
                cin >> a[i][j];
            }
        }
        cnt = 0;
        solve(x, y, d, 0);
    }
    return 0;
}
