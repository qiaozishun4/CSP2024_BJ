#include<bits/stdc++.h>
using namespace std;
int X[11]={0,1,0,-1};
int Y[11]={1,0,-1,0};
int M[1005][1005];
int vis[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m,k,x,y,d,ans=0;
        char c;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        vis[x][y]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                cin>>c;
                M[i][j]=0;
                if(c=='.')
                    M[i][j]=1;
            }
        for(int i=1;i<=k;i++)
        {
            if(M[x+X[d]][y+Y[d]]==1)
            {
                x+=X[d];
                y+=Y[d];
                vis[x][y]=1;
            }
            else
                d=(d+1)%4;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(vis[i][j]==1)
                    ans++;
                vis[i][j]=0;
            }
        cout<<ans<<endl;
    }
    return 0;
}