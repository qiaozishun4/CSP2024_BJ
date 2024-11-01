#include <cstdio>
#include <iostream>
using namespace std;
int n,k,T,m,x,y,d;
char a[1003][1003];
bool vis[1003][1003];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        vis[x][y] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        while(k--)
        {
            if(d == 0)
            {
                if(a[x][y+1] == '.' && y+1 <= m)
                {
                    y = y+1;
                    vis[x][y] = 1;
                }
                else d = (d+1)%4;
                continue;
            }
            else if(d == 1)
            {
                if(a[x+1][y] == '.' && x+1 <= n)
                {
                    x = x+1;
                    vis[x][y] = 1;
                }
                else d = (d+1)%4;
                continue;
            }
            else if(d == 2)
            {
                if(a[x][y-1] == '.' && 1 <= y-1)
                {
                    y = y-1;
                    vis[x][y] = 1;
                }
                else d = (d+1)%4;
                continue;
            }
            else if(d == 3)
            {
                if(a[x-1][y] == '.' && 1 <= x-1)
                {
                    x = x-1;
                    vis[x][y] = 1;
                }
                else d = (d+1)%4;
                continue;
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(vis[i][j])
                {
                    cnt++;
                    vis[i][j] = 0;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
