#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int t;
int n,m,k;
int sx,sy;
int g[N][N];
bool vis[N][N];
int d;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>sx>>sy>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char c;
                cin>>c;
                g[i][j]=c;
            }
        }
        memset(vis,0,sizeof(vis));
        vis[sx][sy]=1;
        while(k--)
        {
            int tx=sx+dx[d];
            int ty=sy+dy[d];
            if(tx>0&&tx<=n&&ty>0&&ty<=m&&g[tx][ty]=='.')
            {
                sx=tx;
                sy=ty;
                vis[tx][ty]=1;
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
                if(vis[i][j])
                {
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
