#include <bits/stdc++.h>
using namespace std;
int t=0,n,m,k,d,xx=0,yy=0,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},ans=1,vis[1000+7][1000+7],nx=0,ny=0;
char mp[1000+7][1000+7];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        cin >> xx >> yy >> d;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> mp[i][j];
        for(int i=1;i<=k;i++)
        {
            nx=xx+dx[d],ny=yy+dy[d];
            if(nx>n||nx<=0||ny>m||ny<=0||vis[nx][ny]==1||mp[nx][ny]=='x') d=(d+1)%4;
            else xx=nx,yy=ny,ans++,vis[nx][ny]=1;
            //cout << xx << " " << yy << " " << d << " " << nx << " " << ny << " " << ans << "\n";
        }
        cout << ans << "\n";ans=0;
        memset(vis,0,sizeof(vis));
    }
    return 0;
}

