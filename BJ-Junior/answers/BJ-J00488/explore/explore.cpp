#include<iostream>
using namespace std;
int t,n,m,k;
int a[1005][1005];// allow --1   no ---0
int vis[1005][1005]={};
long long ans=0;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int i,j;
    cin>>t;
    while(t--)
    {
        char c;
        int x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin>>c;
                if(c=='.')
                    a[i][j]=1;
                else
                    a[i][j]=0;
                vis[i][j]=0;
            }
        }
        vis[x][y]=1;
        for(i=1;i<=k;i++)
        {
            int nx,ny;
            if(d==0)
                nx=x,ny=y+1;
            if(d==1)
                nx=x+1,ny=y;
            if(d==2)
                nx=x,ny=y-1;
            if(d==3)
                nx=x-1,ny=y;
            if(nx>0&&nx<=n&&ny>0&&ny<=m&&a[nx][ny]==1)
            {
                x=nx;
                y=ny;
                vis[x][y]=1;
            }
            else
                d=(d+1)%4;
            //cout<<x<<" "<<y<<" "<<d<<endl;
        }
        ans=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(vis[i][j]==1)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
