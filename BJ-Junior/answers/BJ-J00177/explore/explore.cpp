#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char mp[1005][1005];
bool vis[1005][1005];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        memset(mp, 0, sizeof(mp));
        memset(vis, false, sizeof(vis));
        int n, m, k, x, y, d;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin >> mp[i][j];
        vis[x][y] = true;
        while(k--)
        {

            int nx = x + dx[d];
            int ny = y + dy[d];
            if(1 <= nx && nx <= n && 1 <= ny && ny <= m && mp[nx][ny] == '.')
            {
                x = nx, y = ny;
                vis[x][y] = true;
            }else{
                d = (d + 1) % 4;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                ans += vis[i][j];
        cout << ans <<endl;
    }
    return 0;
}
