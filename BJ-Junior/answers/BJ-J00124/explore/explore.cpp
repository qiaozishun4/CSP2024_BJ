#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, k, x, y, d, cnt = 1;
        cin >> n >> m >> k >> x >> y >> d;
        char a[1005][1005];
        bool vis[1005][1005];
        memset(vis, true, sizeof(vis));
        for(int i = 1;i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                cin >> a[i][j];
        }
        vis[x][y] = false;
        while(k--)
        {
            if(d == 0)
            {
                if(y+1 > m)
                    d = (d+1)%4;
                else if(a[x][y+1] == 'x')
                    d = (d+1)%4;
                else{
                    y++;
                    if(vis[x][y]==true)
                    {
                        cnt++;
                        vis[x][y] = false;
                    }
                }
                continue;
            }
            if(d == 1)
            {

                if(x+1 > n)
                    d = (d+1)%4;
                else if(a[x+1][y] == 'x')
                    d = (d+1)%4;
                else{
                    x++;
                    if(vis[x][y]==true)
                    {
                        cnt++;
                        vis[x][y] = false;
                    }
                }
                continue;
            }
            if(d == 2)
            {

                if(y < 2)
                    d = (d+1)%4;
                else if(a[x][y-1] == 'x')
                    d = (d+1)%4;
                else{
                    y--;
                    if(vis[x][y]==true)
                    {
                        cnt++;
                        vis[x][y] = false;
                    }
                }
                continue;
            }
            if(d == 3)
            {

                if(x < 2)
                    d = (d+1)%4;
                else if(a[x-1][y] == 'x')
                    d = (d+1)%4;
                else{
                    x--;
                    if(vis[x][y]==true)
                    {
                        cnt++;
                        vis[x][y] = false;
                    }
                }
                continue;
            }
        }
        cout << cnt << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
