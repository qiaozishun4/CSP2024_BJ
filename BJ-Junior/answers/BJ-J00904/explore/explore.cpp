#include<bits/stdc++.h>
#define MAXN 2010
using namespace std;

int t,n,m,k;
char c[MAXN][MAXN];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
bool vis[MAXN][MAXN];

void init()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            vis[i][j]=0;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        int x,y,d,ans=1;
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        init();
        getchar();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                c[i][j]=getchar();
            }
            getchar();
        }
        vis[x][y]=1;
        while(k--)
        {
            int xx=x+dir[d][0],yy=y+dir[d][1];
            if(xx<1||xx>n||yy<1||yy>m||c[xx][yy]=='x')
            {
                d=(d+1)%4;
                continue;
            }
            x=xx,y=yy;
            if(!vis[x][y])
            {
                vis[x][y]=1;
                ans+=1;
            }
        }
        printf("%d\n",ans);
    }
    return 0 ;
}
