#include <bits/stdc++.h>
using namespace std;
char a[1010][1010];
bool vis[1010][1010];
int main()
{
    freopen("explore.in" , "r" , stdin);
    freopen("explore.out" , "w" , stdout);
    int t;
    cin >> t;
    while(t --)
    {
        int n , m , k;
        cin >> n >> m >> k;
        int x , y , d;
        cin >> x >> y >> d;
        for(int i = 1; i <= 1000; i++)
        {
            for(int j = 1; j <= 1000; j++)
            {
                a[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        vis[x][y] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        int cnt = 1;
        for(int i = 1; i <= k; i++)
        {
            int nx = x , ny = y;
            if(d == 0)
            {
                ny ++;
            }
            if(d == 1)
            {
                nx ++;
            }
            if(d == 2)
            {
                ny --;
            }
            if(d == 3)
            {
                nx --;
            }
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.')
            {
                x = nx;
                y = ny;
                if(vis[x][y] == 0)
                {
                    cnt ++;
                    vis[x][y] = 1;
                }

            }
            else
            {
                d = (d + 1) % 4;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
