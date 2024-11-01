#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int xn, now_y, dn;
int ans = 0;
bool vis[1005][1005];
char my_mappt[1005][1005];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
void dfs(int x, int y, int d, int nowk)
{
    vis[x][y] = 1;
    if(nowk == 0) return;
    int nx = x + dx[d];
    int ny = y + dy[d];
    if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && my_mappt[nx][ny] == '.')
    {
        if(vis[nx][ny] == 0) ans++;
        dfs(nx, ny, d, nowk - 1);
    }
    else
        dfs(x, y, (d + 1) % 4, nowk - 1);
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        memset(vis, 0, sizeof vis);
        cin >> n >> m >> k >> xn >> now_y >> dn;
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= m; k++)
            {
                cin >> my_mappt[j][k];
                vis[j][k] = 0;
            }
        }
        ans = 0;
        dfs(xn, now_y, dn, k);
        cout << ans + 1 << endl;
    }
    return 0;
}
