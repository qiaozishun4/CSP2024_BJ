#include <bits/stdc++.h>


using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    char mp[1010][1010];
    bool vis[1010][1010];
    memset(vis,0,sizeof(vis));
    int x,y,d;
    cin>>x>>y>>d;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
        }
    }
    int ans=1;
    vis[x][y]=1;

    for(int i=1;i<=k;i++)
    {
        int xx=x+dx[d],yy=y+dy[d];
        if(1<=xx&&xx<=n&&1<=yy&&yy<=m&&mp[xx][yy]!='x')
        {
            x=xx,y=yy;
            if(vis[x][y]==0)
            {
                ans++;
                vis[x][y]=1;
            }
        }
        else
        {
            d++;
            d%=4;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T=0;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
