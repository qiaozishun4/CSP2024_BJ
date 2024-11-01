#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

int n,m,k,x0,y0,d0;
bool vis[1005][1005];
char a[1005][1005];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs()
{
    int x = x0,y = y0,d = d0;
    vis[x][y] = true;
    while(k > 0)
    {
        int zx = x + dx[d],zy = y + dy[d];
        if(zx < 1 || zx > n || zy < 1 || zy > m)
        {
            k--;
            d = (d + 1) % 4;
            continue;
        }
        if(a[zx][zy] == 'x')
        {
            k--;
            d = (d + 1) % 4;
            continue;
        }
        x = zx,y = zy;
        vis[zx][zy] = true;
        k--;
    }
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        cin >> n >> m >> k >> x0 >> y0 >> d0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin >> a[i][j];
            }
        }
        bfs();
        int cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                if(vis[i][j] == true)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
