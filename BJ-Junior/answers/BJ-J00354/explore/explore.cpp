#include<iostream>
using namespace std;
int T,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int main(void)
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        int n,m,k,x,y,d,cnt=1;
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        char mp[n+1][m+1]={};
        bool vis[n+1][m+1]={0};
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>mp[i][j];
        vis[x][y]=1;
        while(--k>=0)
        {
            int dd=d;
            int xx=x+dx[d],yy=y+dy[d];
            if(xx>0&&yy>0&&xx<=n&&yy<=m&&mp[xx][yy]!='x')
            {
                x=xx,y=yy;
                if(vis[x][y]==0)cnt++,vis[x][y]=1;
            }
            else d=(d+1)%4;
        }
        printf("%d\n",cnt);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
