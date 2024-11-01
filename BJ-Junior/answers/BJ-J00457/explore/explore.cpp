#include<bits/stdc++.h>
using namespace std;
int t, n, m, k, cnt;
char a[1005][1005];
bool vis[1005][1005];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        memset(vis, 0, sizeof(vis));
        cnt = 0;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i = 1;i <= k+1;i++)
        {
            if(!vis[x][y]) cnt++;
            vis[x][y] = 1;
            int nx = x+dx[d], ny = y+dy[d];
            if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='x') d = (d+1)%4;
            else x = nx, y = ny;
        }
        cout << cnt << "\n";
    }
    return 0;
}
