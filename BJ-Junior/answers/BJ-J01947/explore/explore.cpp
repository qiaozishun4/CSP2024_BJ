#include <bits/stdc++.h>
using namespace std;
char mp[1005][1005];
int vis[1005][1005];
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int x,y,d;
    cin>>x>>y>>d;
    for(int i=1;i<=n;i++) cin>>(mp[i]+1);
    vis[x][y]=1;
    while(k--)
    {
        int nx,ny;
        if(d==0) nx=x,ny=y+1;
        if(d==1) nx=x+1,ny=y;
        if(d==2) nx=x,ny=y-1;
        if(d==3) nx=x-1,ny=y;
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.')
        {
            vis[nx][ny]=1;
            x=nx,y=ny;
        }
        else d=(d+1)%4;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans+=vis[i][j];
            vis[i][j]=0;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}