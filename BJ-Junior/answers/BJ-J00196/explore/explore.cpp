#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans=0;
char a[1010][1010];
int dx[5]={0,1,0,-1},dy[5]={1,0,-1,0};
bool vis[1010][1010];
void dfs(int x,int y,int d,int cnt,int step)
{
    if(cnt==k)
        return ;
    else if(cnt>k)
    {
        vis[x][y]=0;
        return ;
    }
    //ans=max(ans,step);
    //cout<<x<<" "<<y<<" "<<d<<" "<<cnt<<" "<<step<<endl;
    int nx=x+dx[d],ny=y+dy[d];
    if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.')//&&vis[nx][ny]==0)
    {
       // a[nx][ny]='x';
        vis[nx][ny]=1;
        dfs(nx,ny,d,cnt+1,step+1);
    }
    else
    {
        while(1)
        {
            d=(d+1)%4;
            int nx=x+dx[d],ny=y+dy[d];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.')//&&vis[nx][ny]==0)
            {
             //   a[nx][ny]='x';
                vis[nx][ny]=1;
                dfs(nx,ny,d,cnt+2,step+1);
                break;
            }

            d=(d+1)%4;
            nx=x+dx[d],ny=y+dy[d];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.')//&&vis[nx][ny]==0)
            {
               // a[nx][ny]='x';
                vis[nx][ny]=1;
                dfs(nx,ny,d,cnt+3,step+1);
                break;
            }
            d=(d+1)%4;
            nx=x+dx[d],ny=y+dy[d];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.')//x   &&vis[nx][ny]==0)
            {
                vis[nx][ny]=1;
                //a[nx][ny]='x';
                dfs(nx,ny,d,cnt+4,step+1);
                break;
            }
        }
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        if(k==1)
        {
            int nx=dx[d]+x,ny=dy[d]+y;
            if(a[nx][ny]!='.'||nx<1||nx>n||ny<1||ny>m)
                cout<<1<<endl;
            else
                cout<<2<<endl;
            continue;
        }
        vis[x][y]=1;
        dfs(x,y,d,0,1);
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=m;j++)
                    ans+=vis[i][j];
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
