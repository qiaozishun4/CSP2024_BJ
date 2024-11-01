#include <iostream>
#include <cstring>
using namespace std;
int t,n,m,k,ans;
char a[1007][1007];
int vis[1007][1007];
int x,y,d;
int dx[7]={0,1,0,-1};
int dy[7]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        memset(vis,0,sizeof(vis));
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        vis[x][y]=1;
        ans++;
        for(int i=1;i<=k;i++)
        {
            int nx=x+dx[d];
            int ny=y+dy[d];

            if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='x')
            {
                d=(d+1)%4;
            }
            else
            {
                vis[nx][ny]++;
                if(vis[nx][ny]==1) ans++;
                x=nx,y=ny;
            }
            //cout<<x<<" "<<y<<" "<<d<<" "<<nx<<" "<<ny<<endl;
        }
        printf("%d\n",ans);
    }
    return 0;
}
