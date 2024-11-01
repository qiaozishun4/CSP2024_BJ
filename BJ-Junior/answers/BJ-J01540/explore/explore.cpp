#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int vis[1005][1005];
int n,m,t,k;
int dy[4]={1,0,-1,0},dx[4]={0,1,0,-1};
int sx,sy,d,ans;
void f()
{
    ans=1;
    vis[sx][sy]=1;
    int x=sx,y=sy;
    while(k--)
    {
        int nx=dx[d]+x,ny=dy[d]+y;
        //printf("d=%d,nx=%d,ny=%d\n",d,nx,ny);
        if(nx>0&&nx<=n&&ny>0&&ny<=m&&a[nx][ny]!='x')
        {
            if(vis[nx][ny]==0)
            {
                ans++;
                vis[nx][ny]=1;

            }
            x=nx,y=ny;

        }
        else
        {
            d=(d+1)%4;
        }
    }
    printf("%d\n",ans);
}
void prt()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&sx,&sy,&d);
        //printf("n=%d,m=%d,k=%d\n",n,m,k);
        //printf("sx=%d,sy=%d,d=%d\n",sx,sy,d);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        //prt();
        f();
    }
    return 0;
}
