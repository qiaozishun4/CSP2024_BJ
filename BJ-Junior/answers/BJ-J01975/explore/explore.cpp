#include <bits/stdc++.h>
using namespace std;
int t;
int n,m,k,x,y,l,vis[1005][1005],cnt = 0;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
char g[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cnt = 0;
        cin >> n >> m >> k >> x >> y >> l;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin >> g[i][j];
            }
        }
        memset(vis,0,sizeof vis);
        vis[x][y] = 1;
        for(int i = 1;i <= k;i++)
        {
            int nx = x + dx[l];
            int ny = y + dy[l];
            if(nx > n || ny > m || g[nx][ny] != '.')
            {
                l = (l + 1) % 4;
            }
            else
            {
                x = nx;
                y = ny;
                vis[x][y] = 1;
            }
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                if(vis[i][j] == 1)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
