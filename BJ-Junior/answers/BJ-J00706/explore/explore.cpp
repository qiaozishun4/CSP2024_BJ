#include<bits/stdc++.h>
using namespace std;
int maps[1005][1005];
bool vis[1005][1005];
int n,m,k,x,y,d,ans;
char op;
int xl[]={0,1,0,-1};
int yl[]={1,0,-1,0};
void go()
{
    int tx=x+xl[d];
    int ty=y+yl[d];
    if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&maps[tx][ty])x=tx,y=ty;
    else d=(d+1)%4;
    vis[x][y]=1;
    return ;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.ans","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        memset(maps,0,sizeof(maps));
        ans=0;
        cin>>n>>m>>k>>x>>y>>d;
        vis[x][y]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>op;
                if(op=='.')maps[i][j]=1;
                else maps[i][j]=0;
            }
        }
        for(int i=1;i<=k;i++)go();
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ans+=vis[i][j];
        cout<<ans<<endl;
    }
    return 0;
}
