#include <bits/stdc++.h>
using namespace std;

const int NR = 1005;
int n, m, k, sx, sy, sd;
char mp[NR][NR];
bool vis[NR][NR];

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void dfs(int x, int y, int d, int step)
{
    int st = step;
    for (int i = d; i <= d + 3; i++, st--)
    {
        if (st <= 0) return ;
        int nd = i % 4, nx = x + dx[nd], ny = y + dy[nd];
        if (1 <= nx && nx <= n && 1 <= ny && ny <= m && mp[nx][ny] == '.')
        {
            vis[nx][ny] = true;
            dfs(nx, ny, nd, st - 1);
            return ;
        }
    }
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k >> sx >> sy >> sd;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) cin >> mp[i][j];
        
        memset(vis, false, sizeof(vis));
        vis[sx][sy] = true;
        dfs(sx, sy, sd, k);

        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (vis[i][j]) ans++;
        cout << ans << endl;
    }
    return 0;
}