#include <bits/stdc++.h>
#define ll long long
using namespace std;
char g[1005][1005];
bool vis[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        memset(g,0,sizeof(g));
        int n,m,k,ans=0;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>g[i][j];
            }
        }
        for(int i=1;i<=k+1;i++)
        {
            //cout<<x<<","<<y<<"\n";
            vis[x][y]=1;
            int nx,ny;
            if(d==0) nx=x,ny=y+1;
            else if(d==1) nx=x+1,ny=y;
            else if(d==2) nx=x,ny=y-1;
            else if(d==3) nx=x-1,ny=y;
            if(nx<1||ny<1||nx>n||ny>m||g[nx][ny]=='x')
            {
                d=(d+1)%4;
            }
            else
            {
                //cout<<"okok";
                x=nx;
                y=ny;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                //cout<<vis[i][j];
                if(vis[i][j])
                {
                    ans++;
                }
            }
            //cout<<"\n";
        }
        cout<<ans<<"\n";
    }
    return 0;
}
