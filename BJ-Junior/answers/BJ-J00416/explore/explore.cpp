#include<bits/stdc++.h>
using namespace std;
char g[110][110];
bool vis[110][110];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int u=1;u<=t;u++)
    {
        for(int i=0;i<=100;i++)
        {
            for(int j=0;j<=100;j++)
            {
                g[i][j]=vis[i][j]=0;
            }
        }
        int n,m,k,x,y,d,sum=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>g[i][j];
            }
        }
        for(int i=1;i<=k;i++)
        {
            int xx,yy;
            if(d==0)
            {
                xx=x;
                yy=y+1;
            }
            else if(d==1)
            {
                xx=x+1;
                yy=y;
            }
            else if(d==2)
            {
                xx=x;
                yy=y-1;
            }
            else if(d==3)
            {
                xx=x-1;
                yy=y;
            }
            if(xx<0 || xx>n || yy<0 || yy>m || g[xx][yy]=='x')
            {
                xx=x;
                yy=y;
                d=(d+1)%4;
                vis[x][y]=1;
            }
            else
            {
               vis[xx][yy]=1;
                x=xx;
                y=yy;
                vis[x][y]=1;

            }
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(vis[i][j]==1) sum++;
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}
