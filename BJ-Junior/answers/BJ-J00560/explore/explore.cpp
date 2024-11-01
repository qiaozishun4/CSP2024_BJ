#include <bits/stdc++.h>
using namespace std;
char c[1005][1005];
bool vis[1005][1005];
int cnt;
int n,m,k;
void dfs(int x,int y,int fx,int lef)
{

    if(!vis[x][y] && (x <= n && x >= 1 && y <= m && y >= 1 && c[x][y] != 'x')){
            cnt++;
    }
    vis[x][y] = 1;
    if(!lef) return;

    if(fx == 0)
    {


        if((x > n || x < 1 || y + 1 > m || y + 1 < 1 || c[x][y + 1] == 'x'))
        {
            if(lef != 0) dfs(x,y,(fx+1) % 4,lef - 1);
            else return ;
        }
        else {
            dfs(x,y + 1,fx,lef - 1);
        }
    }
    else if(fx == 1)
    {

        if((x + 1 > n || x + 1 < 1 || y > m || y < 1 || c[x + 1][y] == 'x'))
        {
            if(lef != 0) dfs(x,y,(fx+1) % 4,lef - 1);
            else return ;
        }
        else{
            dfs(x + 1,y,fx,lef - 1);
        }
    }
    else if(fx == 2)
    {

        if((x > n || x < 1 || y - 1 > m || y - 1 < 1 || c[x][y - 1] == 'x'))
        {
            if(lef != 0) dfs(x,y,(fx+1) % 4,lef - 1);
            else return ;
        }
        else{
            dfs(x,y - 1,fx,lef - 1);
        }
    }
    else
    {

        if((x - 1 > n || x - 1 < 1 || y > m || y < 1 || c[x - 1][y] == 'x'))
        {
            if(lef != 0) dfs(x,y,(fx+1) % 4,lef - 1);
            else return ;
        }
        else{
           dfs(x - 1,y,fx,lef - 1);
        }
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cnt = 0;
        memset(vis,0,sizeof(vis));
        int sxx,syy,kk;
        cin >> n >> m >> k;
        cin >> sxx >> syy >> kk;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin >> c[i][j];
            }
        }
        dfs(sxx,syy,kk,k);
        cout << cnt << endl;
    }
    return 0;
}
