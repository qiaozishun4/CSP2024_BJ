#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int t,ans=0;
int n,m,k;
int x0,y0,d0;
char c[1005][1005];
bool vis[1005][1005];

void dfs(int step,int x,int y,int d)
{
    if(step>k)
    {
        cout<<ans<<endl;
        ans=0;
        memset(vis,0,sizeof(vis));

        return ;
    }

    int nx=x,ny=y;
    if(d==0)
    {
        ny++;
        if(nx<1 || nx>n || ny<1 || ny>m || c[nx][ny]=='x')
            dfs(step+1,x,y,(d+1)%4);
        else
        {
            if(!vis[nx][ny])
            {
                vis[nx][ny]=true;
                ans++;
            }

            dfs(step+1,nx,ny,d);
        }
    }
    else if(d==1)
    {
        nx++;
        if(nx<1 || nx>n || ny<1 || ny>m || c[nx][ny]=='x')
            dfs(step+1,x,y,(d+1)%4);
        else
        {
            if(!vis[nx][ny])
            {
                vis[nx][ny]=true;
                ans++;
            }
            dfs(step+1,nx,ny,d);
        }
    }
    else if(d==2)
    {
        ny--;
        if(nx<1 || nx>n || ny<1 || ny>m || c[nx][ny]=='x')
            dfs(step+1,x,y,(d+1)%4);
        else
        {
            if(!vis[nx][ny])
            {
                vis[nx][ny]=true;
                ans++;
            }
            dfs(step+1,nx,ny,d);
        }
    }
    else if(d==3)
    {
        nx--;
        if(nx<1 || nx>n || ny<1 || ny>m || c[nx][ny]=='x')
            dfs(step+1,x,y,(d+1)%4);
        else
        {
            if(!vis[nx][ny])
            {
                vis[nx][ny]=true;
                ans++;
            }
            dfs(step+1,nx,ny,d);
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
        cin>>n>>m>>k;
        cin>>x0>>y0>>d0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c[i][j];
            }
        }
        vis[x0][y0]=true;
        ans++;
        dfs(1,x0,y0,d0);
    }


    return 0;
}
