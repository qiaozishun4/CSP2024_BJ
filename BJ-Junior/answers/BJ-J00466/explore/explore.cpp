#include <iostream>
#include <cstdio>
using namespace std;

int dx[5] = {0,1,0,-1};
int dy[5] = {1,0,-1,0};

int T,n,m,k;
char c[1005][1005];
int vis[1005][1005];
int cnt;

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        int x,y,d;
        cnt = 0;
        scanf("%d %d %d",&n,&m,&k);
        scanf("%d %d %d",&x,&y,&d);
        for(int i = 0;i <= n + 1;i++)
            for(int j = 0;j <= m + 1;j++)
                vis[i][j] = 0;
        vis[x][y] = 1;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                cin >> c[i][j];

        for(int i = 1;i <= k;i++)
        {
 //           cout << d << endl;
            x += dx[d];
            y += dy[d];
            if(x <= 0 || y <= 0 || x > n || y > m || c[x][y] == 'x')
            {
                x -= dx[d];
                y -= dy[d];
                d = (d + 1) % 4;
            }
            else vis[x][y] = 1;
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                //cout << vis[i][j];
                if(c[i][j] == '.' && vis[i][j]) cnt++;
            }
            //cout << endl;
        }
        cout << cnt << endl;
    }
    return 0;
}
