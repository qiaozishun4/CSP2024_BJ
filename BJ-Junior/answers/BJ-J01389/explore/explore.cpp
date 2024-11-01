#include<bits/stdc++.h>
using namespace std;
bool vis[1005][1005];
char g[1005][1005];
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        memset(vis,false,sizeof(vis));
        int ans=1;
        int n,m,k,sx,sy,d;
        cin>>n>>m>>k;
        cin>>sx>>sy>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>g[i][j];
            }
        }
        vis[sx][sy]=true;
        int x=sx,y=sy;
        while(k--)
        {
            int nx,ny;
            nx=x+dx[d];
            ny=y+dy[d];
            if(nx>n||nx<1||ny>m||ny<1)d=(d+1)%4;
            else if(g[nx][ny]=='x')d=(d+1)%4;
            else x=nx,y=ny;
            if(vis[x][y]==false)
            {
                ans++;
                vis[x][y]=true;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
