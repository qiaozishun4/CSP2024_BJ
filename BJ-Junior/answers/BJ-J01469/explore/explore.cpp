#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int sx,sy,sd;
char mp[1001][1001];
bool vis[1001][1001];
int d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int ans;

void dfs(int x,int y,int di,int cnt)
{
    if(vis[x][y] == false)
    {
        vis[x][y] = true;
        ans++;
    }
    if(cnt >= k)
    {
        return ;
    }
    int dx = x + d[di][0];
    int dy = y + d[di][1];
    if(dx >= 1 && dx <= n && dy >= 1 && dy <= m && mp[dx][dy] == '.')
    {
        dfs(dx,dy,di,cnt + 1);
    }
    else
    {
        dfs(x,y,(di + 1) % 4,cnt + 1);
    }
    return ;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    for(int times = 1;times <= t;times++)
    {
        ans = 0;
        memset(vis,false,sizeof(vis));
        cin >> n >> m >> k;
        cin >> sx >> sy >> sd;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin >> mp[i][j];
            }
        }
        dfs(sx,sy,sd,0);
        cout << ans << endl;
    }
    return 0;
}
