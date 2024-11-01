#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int t,n,m,k,x,y,d,ans;
char mp[1005][1005];
bool vis[1005][1005];
void f(int x,int y,int d)
{
    int nx,ny;
    for(;;)
    {
        if(!vis[x][y])
            ans++;
        //printf("x%d y%d dir%d\n",x,y,d);//debug
        if(k--<=0)return;
        vis[x][y]=true;
        if(d==0)nx=x,ny=y+1;
        if(d==1)nx=x+1,ny=y;
        if(d==2)nx=x,ny=y-1;
        if(d==3)nx=x-1,ny=y;
        if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&mp[nx][ny]=='.')
            x=nx,y=ny;//f(nx,ny,d);
        else
            d=(d+1)%4;//f(x,y,(d+1)%4);
    }
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>m>>k>>x>>y>>d;
        ans=0;
        for(int j1=1;j1<=n;j1++)
            for(int j2=1;j2<=m;j2++)
            {
                cin>>mp[j1][j2];
                vis[j1][j2]=false;
            }
        f(x,y,d);
        cout<<ans<<endl;
    }

    return 0;
}
