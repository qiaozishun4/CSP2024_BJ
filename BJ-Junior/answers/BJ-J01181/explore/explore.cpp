#include <bits/stdc++.h>

using namespace std;

int t,n,m,k,xx,yy,dd;
char a[1005][1005];
bool vis[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int ans=0;
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&xx,&yy,&dd);
        for(int j=1;j<=n;j++)
        {
            for(int l=1;l<=m;l++)cin>>a[j][l];
        }
        vis[xx][yy]=1;
        for(int j=1;j<=k;j++)
        {
            int nx=xx+dx[dd],ny=yy+dy[dd];
            if(nx<=0||ny<=0||nx>n||ny>m)
            {
                dd=(dd+1)%4;
                continue;
            }
            if(a[nx][ny]=='x')
            {
                dd=(dd+1)%4;
                continue;
            }
            vis[nx][ny]=1;
            xx=nx;
            yy=ny;
        }
        for(int j=1;j<=n;j++)
        {
            for(int l=1;l<=m;l++)
            {
                if(vis[j][l])ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
