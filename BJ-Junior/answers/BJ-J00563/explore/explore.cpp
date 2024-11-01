#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool vis[1005][1005];
int p[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
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
        int cnt=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        vis[x][y]=1;
        int kx=x,ky=y,kd=d;
        while(k--)
        {
            int u=kx+p[kd][0],v=ky+p[kd][1];
            if(u>=1&&u<=n&&v>=1&&v<=m&&a[u][v]=='.')
            {
                kx=u,ky=v;
                if(vis[u][v]==0)
                {
                    cnt++;
                }
                vis[u][v]=1;
            }
            else
            {
                kd=(kd+1)%4;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
