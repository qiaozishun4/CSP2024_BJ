#include<bits/stdc++.h>
using namespace std;
int n,m,k;
char mp[1005][1005];
bool vis[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int bs=0;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    scanf("%d",&T);
    int x,y,d;
    while(T--)
    {
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        for(int i=1;i<=n;i++)mp[i][m+1]='X';
        for(int j=1;j<=m;j++)mp[n+1][j]='X';
        bs=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>mp[i][j];
                vis[i][j]=0;
            }
        }
        if(k==0)
        {
            printf("1\n");
            continue;
        }
        while(bs<=k)
        {
            vis[x][y]=1;
            while(mp[x+dx[d]][y+dy[d]]!='.'||x+dx[d]<1||y+dy[d]<1||x+dx[d]>n||y+dy[d]>m)
            {
                d=(d+1)%4;
                bs++;
                if(bs==k)
                {
                    break;
                }
            }
            if(bs==k)break;
            bs++;
            x=x+dx[d];
            y=y+dy[d];
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(vis[i][j])
                {
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
}
