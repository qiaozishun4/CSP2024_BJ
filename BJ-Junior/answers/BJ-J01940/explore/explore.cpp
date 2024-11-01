#include <bits/stdc++.h>
using namespace std;
int n,t,m,k,sx,sy,sd;
int ans;
char g[1010][1010];
string s;
int dfs(int x,int y,int d,int cur)
{
        if(cur<1)
    {
        return ans;
    }
    if(d==0)
    {
        if(y+1<=m&&g[x][y+1]=='.')
        {
            ans++;
            g[x][y+1]='!';
            dfs(x,y+1,d,cur-1);
        }
        else if(y+1<=m&&g[x][y+1]=='!')
        {
            dfs(x,y+1,d,cur-1);
        }
        else
        {
            d+=1;
            dfs(x,y,d,cur-1);
        }
    }
    else if(d==1)
    {
        if(x+1<=n&&g[x+1][y]=='.')
        {
            ans++;
            g[x+1][y]='!';
            dfs(x+1,y,d,cur-1);
        }
        else if(x+1<=n&&g[x+1][y]=='!')
        {
            dfs(x+1,y,d,cur-1);
        }
        else
        {
            d+=1;
            dfs(x,y,d,cur-1);
        }
    }
    else if(d==2)
    {
        if(y-1>=1&&g[x][y-1]=='.')
        {
            ans++;
            g[x][y-1]='!';
            dfs(x,y-1,d,cur-1);
        }
        else if(y-1>=1&&g[x][y-1]=='!')
        {
            dfs(x,y-1,d,cur-1);
        }
        else
        {
            d+=1;
            dfs(x,y,d,cur-1);
        }
    }
    else if(d==3)
    {
        if(x-1>=1&&g[x-1][y]=='.')
        {
            ans++;
            g[x-1][y]='!';
            dfs(x-1,y,d,cur-1);
        }
        else if(x-1>=1&&g[x-1][y]=='!')
        {
            dfs(x-1,y,d,cur-1);
        }
        else
        {
            d=0;
            dfs(x,y,d,cur-1);
        }
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=1;
        cin>>n>>m>>k;
        cin>>sx>>sy>>sd;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>g[i][j];
        g[sx][sy]='!';
        cout<<dfs(sx,sy,sd,k)<<"\n";
    }
    return 0;
}
