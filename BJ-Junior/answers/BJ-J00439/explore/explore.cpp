#include <iostream>
using namespace std;
bool map[1010][1010],vis[1010][1010];
int n,m,t,xx,yy,dd,k,dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0},cnt;
char c;
void dfs(int step,int x,int y,int d)
{
    if(step > k)
    {
        return ;
    }
    if(vis[x][y] == 0)
    {
        cnt++;
        vis[x][y] = 1;
    }
    if(map[x+dx[d]][y+dy[d]] || x+dx[d] < 1 || x+dx[d] > n || y+dy[d] < 1 || y+dy[d] > m)
    {
        dfs(step+1,x,y,(d+1)%4);
    }
    else
    {
        dfs(step+1,x+dx[d],y+dy[d],d);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cnt = 0;
        for(int i = 1;i <= 1000;i++)
        {
            for(int j = 1;j <= 1000;j++)
            {
                map[i][j] = false;
                vis[i][j] = false;
            }
        }
        cin >> n >> m >> k >> xx >> yy >> dd;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin >> c;
                if(c == '.')
                {
                    map[i][j] = false;
                }
                else
                {
                    map[i][j] = true;
                }
            }
        }
        dfs(0,xx,yy,dd);
        cout << cnt << '\n';
    }
    return 0;
}