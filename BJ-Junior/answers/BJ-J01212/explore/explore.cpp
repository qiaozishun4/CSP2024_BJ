#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
bool vis[N][N];
int main()
{
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        char mp[n+1][m+1];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                vis[i][j]=0;
            }
        }
        int x0,y0,d0;
        cin>>x0>>y0>>d0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>mp[i][j];
            }
        }
        vis[x0][y0]=1;
        int xx,yy;
        for(int i=1;i<=k;i++)
        {
            xx=x0+dx[d0];
            yy=y0+dy[d0];
            if(1<=xx&&xx<=n&&1<=yy&&yy<=m&&mp[xx][yy]=='.')
            {
                x0+=dx[d0];
                y0+=dy[d0];
                vis[x0][y0]=1;
            }
            else
            {
                d0=(d0+1)%4;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(vis[i][j]==1)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
