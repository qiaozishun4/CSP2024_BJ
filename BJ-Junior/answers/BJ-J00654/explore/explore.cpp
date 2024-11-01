#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, m, k, s[4][1010][1010];
char mp[1010][1010];
bool vis[1010][1010];
const int walk[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int x, int y, int d, int step)
{
    vis[x][y] = true;
    if(step == k) return ;
    int u = x + walk[d][0], v = y + walk[d][1];
    if(1 <= u && u <= n && 1 <= v && v <= m && mp[u][v] == '.')
        dfs(u, v, d, step + 1);
    else dfs(x, y, (d + 1) % 4, step + 1);
}

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        memset(s, 0, sizeof s);
        memset(mp, 0, sizeof mp);
        memset(vis, 0, sizeof vis);
        int x0, y0, d0;
        cin >> n >> m >> k >> x0 >> y0 >> d0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin >> mp[i][j];

        dfs(x0, y0, d0, 0);
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cnt += vis[i][j];
        cout << cnt << endl;
    }
    return 0;
}
