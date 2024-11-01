#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
bool vis[1010][1010];
int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};

void clean()
{
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            a[i][j]=0;
            vis[i][j]=false;
        }
    }
}
bool check(int x,int y,int n,int m)
{
    //cout<<m<<" "<<n<<" ";
    if(x<=n&&x>=1&&y<=m&&y>=1&&a[x][y]==0) return 1;
    return 0;
}
int dfs(int sx,int sy,int sd,int k,int n,int m)
{
    int x=sx,y=sy,d=sd;
    vis[sx][sy]=1;
    int cnt=1;
    while(k--)
    {
        int nx=x+fx[d];
        int ny=y+fy[d];
        if(check(nx,ny,n,m))
        {
            if(!vis[nx][ny]) cnt++;
            vis[nx][ny]=1;
            x=nx,y=ny;
        }
        else
        {
            d=(d+1)%4;
        }
    }
    return cnt;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {

        char te;
        int n=0,m=0,k=0,sx=0,sy=0,sd=0;
        //scanf("%d%d%d%d%d%d",&n,&m,&k,&sx,&sy,&sd);
        cin>>n>>m>>k>>sx>>sy>>sd;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {

                cin>>te;
                //scanf("%c",&te);
                if(te=='x') a[i][j]=1;
            }
        }
        int ans=dfs(sx,sy,sd,k,n,m);
        printf("%d\n",ans);
        clean();
    }
     return 0;
}
