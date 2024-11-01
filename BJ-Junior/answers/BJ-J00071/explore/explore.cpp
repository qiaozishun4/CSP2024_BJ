#include<bits/stdc++.h>
using namespace std;

int t,n,m,k;
int x,y,d;
char a[10000][10000];
bool vis[10000][10000];
int ans=0;

bool wall(int nx,int ny,int direct)
{
    if(direct==0)ny++;
    if(direct==1)nx++;
    if(direct==2)ny--;
    if(direct==3)nx--;
    if(a[nx][ny]=='.'&&nx>0&&nx<=n&&ny>0&&ny<=m)
    {
        return 1;
    }
    return 0;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        //if(vis[x][y]==0)ans++;
        for(int j=1;j<=n;j++)
        {
            for(int l=1;l<=m;l++)
            {
                cin>>a[j][l];
                vis[j][l]=0;
            }
        }
        for(int j=1;j<=k;j++)
        {
            vis[x][y]=1;
            if(wall(x,y,d)==1)
            {
                //cout<<"true"<<endl;
                if(d==0)y++;
                if(d==1)x++;
                if(d==2)y--;
                if(d==3)x--;
            }
            else
            {
                d=d+1;
                d=d%4;
            }
            //cout<<x<<" "<<y<<" "<<d<<endl;
            vis[x][y]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                //cout<<vis[i][j]<<" ";
                if(vis[i][j]==1)ans++;
            }
            //cout<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
