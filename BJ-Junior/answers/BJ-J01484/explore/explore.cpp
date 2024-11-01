#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,k,x,y,d;
char c[1005][1005];
bool vis[1005][1005];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c[i][j];
            }
        }
        memset(vis,0,sizeof(vis));
        vis[x][y]=true;
        for(int i=1;i<=k;i++)
        {
            int nx=x+dx[d],ny=y+dy[d];
            if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&c[nx][ny]=='.')
            {
                vis[nx][ny]=true;
                x=nx;
                y=ny;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(vis[i][j]) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
