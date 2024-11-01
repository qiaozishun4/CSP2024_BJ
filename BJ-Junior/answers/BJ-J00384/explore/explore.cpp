#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m, k, X, Y, d;
char e[N][N], vis[N][N];
void ipt ()
{
    scanf ("%d%d%d", &n, &m, &k);
    scanf ("%d%d%d", &X, &Y, &d);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> e[i][j];
            vis[i][j] = 0;
        }
    }
}
bool ck (int x, int y)
{
    if (1 <= x && x <= n && 1 <= y && 1 <= m && e[x][y] == '.') return true;
    return false;
}
void solve ()
{
    while (k--)
    {
        vis[X][Y] = true;
        int nx, ny;
        if (d == 0) nx = X, ny = Y + 1; 
        if (d == 1) nx = X + 1, ny = Y;
        if (d == 2) nx = X, ny = Y - 1;  
        if (d == 3) nx = X - 1, ny = Y; 
        if (ck (nx, ny)) X = nx, Y = ny, vis[X][Y] = true;
        else d = (d + 1) % 4;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (vis[i][j]) ans ++;
    cout << ans << endl;
}
int main ()
{
    freopen ("explore.in", "r", stdin);
    freopen ("explore.out", "w", stdout);
    int T; cin >> T;
    while (T--)
    {
        ipt ();
        solve ();
    }
    return 0;
}