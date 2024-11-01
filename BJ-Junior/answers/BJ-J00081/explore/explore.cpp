#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char mp[1005][1005];
bool vis[1005][1005];
int dx[5] = {0,1,0,-1};
int dy[5] = {1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        int n,m,k,sx,sy,sd;
        cin >> n >> m >> k >> sx >> sy >> sd;
        int x = sx,y = sy,d = sd;
        vis[sx][sy] = 1;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin >> mp[i][j];
            }
        }
        for(int i = 1;i <= k;i++)
        {

            int nx = dx[d] + x,ny = dy[d] + y;
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] == '.')
            {
                x = nx;
                y = ny;
                vis[x][y] = 1;
            }
            else
            {
                d = (d+1) % 4;
            }
        }
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                if(vis[i][j]) ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
