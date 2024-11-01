#include<bits/stdc++.h>
using namespace std;
char g[1010][1010];
bool vis[1010][1010];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof vis);
        int n,m,k,x,y,d,ans=0;
        cin>>n>>m>>k>>x>>y>>d;
        vis[x][y]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)cin>>g[i][j];
        for(int i=1;i<=k;i++)
        {
            int nx=x+dx[d],ny=y+dy[d];
            if(nx<1||nx>n||ny<1||ny>m||g[nx][ny]=='x')d=(d+1)%4;
            else{
                x=nx;
                y=ny;
                vis[x][y]=1;
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                ans+=vis[i][j];
            }
        cout<<ans<<endl;
    }
    return 0;
}