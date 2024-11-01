#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char a[N][N];
bool vis[N][N];
int f[] = {0, 1, 0, -1};
int g[] = {1, 0, -1, 0};
int n, m, k;
int x, y, d;
bool in(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        long long ans = 1;
        memset(vis, 0, sizeof(vis));
        vis[x][y] = 1;
        for(int i = 1; i <= k; i++)
        {
            int nx = x + f[d];
            int ny = y + g[d];
            if(a[nx][ny] != 'x' && in(nx, ny))
            {
                x = nx;
                y = ny;
                if(!vis[nx][ny])
                {
                    ans++;
                    vis[nx][ny] = 1;
                }
            }
            else
            {
                d = (d + 1) % 4;
            }
        }
        cout << ans << endl;
    }




    return 0;
}
