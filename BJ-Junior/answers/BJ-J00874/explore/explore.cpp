#include <bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,t;
int d;
char a[10005][10005];
int vis[10005][10005];
long long ans=1;
void dfs(long long x,long long y,int d,long long k)
{
    if(k==0)return ;
    //next step;
    k--;
    long long xx=0,yy=0;
    if(d==0)
    {
        xx=x;
        yy=y+1;
    }
    else if(d==1)
    {
        xx=x+1;
        yy=y;
    }
    else if(d==2)
    {
        xx=x;
        yy=y-1;
    }
    else{
        xx=x-1;
        yy=y;
    }
    //check

    if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]=='.')
    {
        if(vis[xx][yy]==0)
        {
            vis[xx][yy]=1;
            ans++;
        }
        dfs(xx,yy,d,k);
    }
    else
    {
        xx=x,yy=y;
        d=(d+1)%4;
        dfs(xx,yy,d,k);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        ans=1;
        vis[x][y]=1;
        dfs(x,y,d,k);
        cout<<ans<<endl;
    }
   fclose(stdin);
   fclose(stdout);
    return 0;
}
