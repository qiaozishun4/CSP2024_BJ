#include<bits/stdc++.h>
using namespace std;

int n, m, k, T, x, y, d;
char a[1010][1010];
bool vis[1010][1010];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool in(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= m; j ++)
            {
                cin >> a[i][j];
            }
        }
        memset(vis, 0, sizeof(vis));
        vis[x][y] = 1;
        while(k--)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(in(nx, ny) && a[nx][ny] == '.')
            {
                vis[nx][ny] = 1;
                x = nx, y = ny;
            }
            else d = (d+1)%4;
        }
        int ans = 0;
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= m; j ++)
                ans += vis[i][j];
        cout << ans << '\n';
    }
    return 0;
}
