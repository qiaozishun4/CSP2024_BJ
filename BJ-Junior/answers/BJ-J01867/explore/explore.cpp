#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int x,y,d;
char g[1005][1005];
bool vis[1005][1005];
int ans;
int u;
bool check(int xx,int yy)
{
    if(yy<=m&&xx<=n&&g[xx][yy]!='x'&&yy>0&&xx>0)
    {
        return true;
    }
    return false;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        u=0;
        ans=1;
        memset(vis,false,sizeof(vis));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>g[i][j];
                if(g[i][j]=='.')
                {
                    u++;
                }
            }
        }
        vis[x][y]=true;
        while(k--)
        {
            if(d==0)
            {
                if(check(x,y+1))
                {
                    if(!vis[x][y+1])
                    {
                        ans++;
                        vis[x][y+1]=true;
                    }
                    y++;
                }
                else
                {
                    d++;
                }
            }
            else if(d==1)
            {
                if(check(x+1,y))
                {
                    if(!vis[x+1][y])
                    {
                        ans++;
                        vis[x+1][y]=true;
                    }
                    x++;
                }
                else
                {
                    d++;
                }
            }
            else if(d==2)
            {
                if(check(x,y-1))
                {
                    if(!vis[x][y-1])
                    {
                        ans++;
                        vis[x][y-1]=true;
                    }
                    y--;
                }
                else
                {
                    d++;
                }
            }
            else
            {
                if(check(x-1,y))
                {
                    if(!vis[x-1][y])
                    {
                        ans++;
                        vis[x-1][y]=true;
                    }
                    x--;
                }
                else
                {
                    d=0;
                }
            }
            if(ans>=u)
            {
                break;
            }
        }
        if(ans>=u)
        {
            cout<<u<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
    return 0;
}