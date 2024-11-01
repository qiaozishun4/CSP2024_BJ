#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int bx,by,f;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char dis[1005][1005];
bool vis[1005][1005];
int ans;
void dfs(int nx,int ny,int f,int step)
{
    if(step==k+1)return;
    int sx=nx+dx[f];
    int sy=ny+dy[f];
    if(sx>=1&&sx<=n&&sy>=1&&sy<=m&&dis[sx][sy]=='.')
    {
        if(vis[sx][sy]==0)
        {
            vis[sx][sy]=1;
            ans++;
        }
        dfs(sx,sy,f,step+1);
    }
    else
    {
        dfs(nx,ny,(f+1)%4,step+1);
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
        memset(dis,0,sizeof(dis));
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>bx>>by>>f;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>dis[i][j];
            }
        }
        vis[bx][by]=1;
        dfs(bx,by,f,1);
        cout<<ans<<endl;
    }
    return 0;
}
