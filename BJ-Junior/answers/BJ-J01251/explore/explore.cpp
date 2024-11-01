#include<bits/stdc++.h>
using namespace std;
int vis[1005][1005];
char p[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,n,m,t,x,y,d,ans=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d%d",&n,&m,&t,&x,&y,&d);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",&p[i]);
            for(int j=0;j<m;j++)
            {
                vis[i][j]=0;
            }
        }
        y--;
        vis[x][y]=1;
        while(t--)
        {
            if(x+dx[d]>=1&&x+dx[d]<=n&&y+dy[d]>=0&&y+dy[d]<m)
            {
                if(p[x+dx[d]][y+dy[d]]=='.')
                {
                    x+=dx[d];
                    y+=dy[d];
                }
                else
                    d=(d+1)%4;
            }
            else
                d=(d+1)%4;
            vis[x][y]=1;
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans+=vis[i][j];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
