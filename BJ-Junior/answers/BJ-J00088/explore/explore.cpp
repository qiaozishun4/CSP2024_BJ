#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
bool vis[1001][1001];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j],vis[i][j]=0;
        vis[x][y]=1;
        while(k--)
        {
            int nx,ny;
            if(d==0)nx=x,ny=y+1;
            if(d==1)nx=x+1,ny=y;
            if(d==2)nx=x,ny=y-1;
            if(d==3)nx=x-1,ny=y;
            if(nx<1||nx>n||ny<1||ny>m)
            {
                d=(d+1)%4;
                continue;
            }
            else if(a[nx][ny]=='x')
            {
                d=(d+1)%4;
                continue;
            }
            else
            {
                x=nx;
                y=ny;
                vis[x][y]=1;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(vis[i][j])cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}
