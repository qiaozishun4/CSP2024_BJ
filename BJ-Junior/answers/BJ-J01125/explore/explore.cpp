#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool visit[1005][1005];
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int sx,sy,sd;
        scanf("%d%d%d",&sx,&sy,&sd);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]+1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                visit[i][j]=false;
            }
        }
        int x=sx,y=sy,d=sd;
        visit[sx][sy]=true;
        for(int i=1;i<=k;i++)
        {
            int nx=x+dx[d],ny=y+dy[d];
            if(nx<=0||nx>n||ny<=0||ny>m||a[nx][ny]=='x')
            {
                d=(d+1)%4;
                continue;
            }
            x=nx;
            y=ny;
            visit[x][y]=true;
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(visit[i][j]==true)
                {
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
