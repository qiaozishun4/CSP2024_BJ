#include <bits/stdc++.h>
using namespace std;
char g[1005][1005];
int n,m,k;
int dfs(int x,int y,int dir,int step)
{
    if (k == 0)
    {
        if (x>=1&&x<=n&&y>=1&&y<=n&&g[x][y]=='.')
            return step;
        else
            return step+1;
    }
    k--;
    if (dir == 0)
    {
        if (g[x][y+1]=='x'||x<0||x>n||y+1<0||y+1>m)
            dfs(x,y,(dir+1)%4,step);
        else
            dfs(x,y+1,dir,step+1);
    }
    else if (dir == 1)
    {
        if (g[x+1][y]=='x'||x+1<0||x+1>n||y<0||y>m)
            dfs(x,y,(dir+1)%4,step);
        else
            dfs(x+1,y,dir,step+1);
    }
    else if (dir == 2)
    {
        if (g[x][y-1]=='x'||x<0||x>n||y-1<0||y-1>m)
            dfs(x,y,(dir+1)%4,step);
        else
            dfs(x,y-1,dir,step+1);
    }
    else if (dir == 3)
    {
        if (g[x-1][y]=='x'||x-1<0||x-1>n||y<0||y>m)
            dfs(x,y,(dir+1)%4,step);
        else
            dfs(x-1,y,dir,step+1);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int i,j,t,x,y,d;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                cin >> g[i][j];
        cout << dfs(x,y,d,0) << "\n";
    }
    return 0;
}