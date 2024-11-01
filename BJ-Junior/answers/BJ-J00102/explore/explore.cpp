#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool vis[1005][1005];
char ch[1005][1005];

bool in(int x, int y)
{
    return (x >= 1 && y >= 1 && x <= n && y <= m);
}

void dfs(int x, int y, int d, int cnt)
{
    if (cnt == k) return;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[(d + i) % 4], ny = y + dy[(d + i) % 4];
        if (in(nx, ny) && ch[nx][ny] == '.')
        {
            vis[nx][ny] = 1;
            dfs(nx, ny, (d + i) % 4, ++cnt);
            break;
        }
        else cnt++;
        if (cnt == k) break;
    }
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        memset(vis, 0, sizeof(vis));
        int x, y, d;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> ch[i][j];
            }
        }
        vis[x][y] = 1;
        dfs(x, y, d, 0);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (vis[i][j] == 1) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
