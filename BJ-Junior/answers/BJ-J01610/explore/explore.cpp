#include<bits/stdc++.h>
using namespace std;

int T, n, m, k, x, y, d, nx, ny;
char a[1005][1005];
bool vis[1005][1005];

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        memset(vis, 0, sizeof(vis));
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        vis[x][y] = 1;
        while(k--)
        {
            if(d == 0) nx = x, ny = y+1;
            if(d == 1) nx = x+1, ny = y;
            if(d == 2) nx = x, ny = y-1;
            if(d == 3) nx = x-1, ny = y;
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.')
            {
                vis[nx][ny] = 1;
                x = nx, y = ny;
            }
            else
            {
                d = (d+1)%4;
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(vis[i][j]) cnt++;
            }
        }
        cout << cnt <<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

