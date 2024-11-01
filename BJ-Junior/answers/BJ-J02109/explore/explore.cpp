#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,cnt;
struct nod1{int x,y,d;};
nod1 st;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool mapp[1001][1001];
bool vis[1001][1001];
char s[1001];
void bfs()
{
    nod1 tou,wei;
    tou=st;
    vis[tou.x][tou.y]=true;
    cnt=1;
    for(int i=1;i<=k;i++)
    {
        wei.x=tou.x+dx[tou.d];
        wei.y=tou.y+dy[tou.d];
        if(wei.x>=1&&wei.x<=n&&wei.y>=1&&wei.y<=m&&!mapp[wei.x][wei.y])
        {
            tou.x=wei.x;
            tou.y=wei.y;
            if(vis[tou.x][tou.y]==false)
            {
                vis[tou.x][tou.y]=true;
                cnt++;
            }
        }
        else
        {
            tou.d=(tou.d+1)%4;
        }
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&st.x,&st.y,&st.d);
        memset(mapp,false,sizeof(mapp));
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s);
            for(int j=0;j<m;j++)
                if(s[j]=='x')
                    mapp[i][j+1]=true;
        }
        bfs();
        printf("%d\n",cnt);
    }
    return 0;
}
