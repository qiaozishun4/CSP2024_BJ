#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e3 + 10;
char a[N][N];
int wk[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void solve()
{
    int n, m, k, x, y, d, ans = 1;
    cin >> n >> m >> k >> x >> y >> d;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    a[x][y] = '*';
    while (k--)
    {
        int nx = x + wk[d][0], ny = y + wk[d][1];
        if (nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == 'x') d = (d + 1) % 4;
        else 
        {
            if (a[nx][ny] == '.') ans++;
            a[nx][ny] = '*'; x = nx; y = ny;
        }
    }
    cout << ans << endl;
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}