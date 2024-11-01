#include<bits/stdc++.h>
using namespace std;
char c[1005][1005];
bool vis[1005][1005];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    int n,m,k;
    int x,y,d;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin>>c[i][j];
            }
        }
        int ans=1;
        vis[x][y]=1;
        while(k--)
        {
            int gx=x+dx[d];
            int gy=y+dy[d];
            if(gx<=n&&gy<=m&&
            c[gx][gy]=='.')
            {
                if(!vis[gx][gy])ans++;
                vis[gx][gy]=1;
                x=gx;
                y=gy;
            }
            else
            {
                d++;
                d%=4;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}