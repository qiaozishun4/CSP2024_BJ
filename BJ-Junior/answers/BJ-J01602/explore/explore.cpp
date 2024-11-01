#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e3 + 10;
char mp[N][N];
bool vis[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int x0, y0, d0;
        cin >> x0 >> y0 >> d0;
        memset(mp, 0, sizeof(mp));
        memset(vis, 0, sizeof(vis));
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin >> mp[i][j];
            }
        }
        ll ans = 1;
        int x = x0, y = y0, d = d0;
        vis[x][y] = 1;
        for(int i = 1;i <= k;i++)
        {
            int nx = x + dx[d], ny = y + dy[d], lj = 0;
            if(nx < 1 || ny < 1 || nx > n || ny > m || mp[nx][ny] == 'x')
            {
                d = (d + 1) % 4;
                continue;
            }
            if(vis[nx][ny] == 0)
            {
                ans++;
                vis[nx][ny] = 1;
            }
            x = nx, y = ny;
        }
        cout << ans << "\n";
    }
    return 0;
}