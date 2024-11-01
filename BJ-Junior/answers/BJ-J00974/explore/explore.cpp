#include<bits/stdc++.h>
using namespace std;
int n,m,t,k;
int x,y,d;
char tmp;
int cnt;
int mapp[10005][10005];
int vis[10005][10005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    memset(vis,false,sizeof(vis));
    memset(mapp,1,sizeof(vis));
    scanf("%d",&t);
    for(int aq=1;aq<=t;aq++)
    {
        cnt=0;
        memset(vis,false,sizeof(vis));
        memset(mapp,1,sizeof(vis));
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>tmp;
            if(tmp=='.')mapp[i][j]=0;
            if(tmp=='x')mapp[i][j]=1;
        }
        for(int i=1;i<=k;i++)
        {
            if(mapp[x+dx[d]][y+dy[d]]==0)
            {
				if(cnt==0)cnt++;
                x+=dx[d];
                y+=dy[d];
                //printf(" ok:%d %d \n",x,y);
            }
            else
            {
				//printf("nok %d ",d);
				d=(d+1)%4;
				//printf("%d\n",d);
			}
            //printf("cnt:%d\n",cnt);
            if(vis[x][y]!=true)
            {
				cnt++;
                vis[x][y]=true;
            }
        }

        printf("%d\n",cnt);
    }
    return 0;
}
