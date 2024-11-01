#include<bits/stdc++.h>
using namespace std;
#define int long long
char g[1005][1005];
int t,n,m,k,ans,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
bool vis[1005][1005];
struct robot
{
    int x,y,d;
    void go()
    {
        int nx=x+dx[d],ny=y+dy[d];
        if (g[nx][ny]=='x')
            d=(d+1)%4;
        else
            x=nx,y=ny;
    }
} r;
signed main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i,j;
    cin>>t;
    while (t--)
    {
        cin>>n>>m>>k>>r.x>>r.y>>r.d;
        memset(g,'x',sizeof g);
        memset(vis,0,sizeof vis);
        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++)
                cin>>g[i][j];
        for (vis[r.x][r.y]=i=1;i<=k;i++)
        {
            r.go();
            vis[r.x][r.y]=1;
        }
        for (ans=0,i=1;i<=n;i++)
            for (j=1;j<=m;j++)
                ans+=vis[i][j];
        cout<<ans<<endl;
    }
}
