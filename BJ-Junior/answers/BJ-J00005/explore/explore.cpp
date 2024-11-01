#include<bits/stdc++.h>
#define int long long
using namespace std;

int t;
void Main()
{
    int n, m, k, x, y, d, ans = 1;
    bool f[1010][1010] = {};
    char c[1010][1010] = {};
    cin >> n >> m >> k >> x >> y >> d;
    f[x][y] = true;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> c[i][j];
    for(int i = 1; i <= k; i++)
    {
        int nx, ny;
        if(d == 0) nx = x, ny = y + 1;
        if(d == 1) nx = x + 1, ny = y;
        if(d == 2) nx = x, ny = y - 1;
        if(d == 3) nx = x - 1, ny = y;

        if(1 <= nx && nx <= n && 1 <= ny && ny <= m && c[nx][ny] == '.')
        {
            x = nx;
            y = ny;
            if(!f[nx][ny]) f[nx][ny] = true, ans++;
        }
        else d = (d + 1) % 4;
    }
    cout << ans << endl;
}
signed main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        Main();
    }
    return 0;
}
