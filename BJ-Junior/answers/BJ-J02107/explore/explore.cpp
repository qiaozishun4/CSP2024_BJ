#include<bits/stdc++.h>
using namespace std;
const int N=1010;
char s[N][N];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int vis[N][N];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int x,y,d;
        scanf("%d%d%d",&x,&y,&d);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s[i]+1);
        }
        vis[x][y]=1;
        for(int i=1;i<=k;i++)
        {
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(nx<1||nx>n||ny<1||ny>m)
            {
                d=(d+1)%4;
                continue;
            }
            if(s[nx][ny]=='x')
            {
                d=(d+1)%4;
                continue;
            }
            x=nx;
            y=ny;
            vis[x][y]=1;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(vis[i][j]==1)
                {
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
