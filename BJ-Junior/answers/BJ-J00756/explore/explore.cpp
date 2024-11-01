#include<iostream>
#include<cstring>
using namespace std;
int xx[5]={0,1,0,-1};
int yy[5]={1,0,-1,0};
int t;
int n,m,k;
int x,y,d;
int ans;
char mp[1010][1010];
bool vis[1010][1010];
bool check(int x0,int y0,int d0)
{
    x0+=xx[d0];
    y0+=yy[d0];
    if(x0==0||x0==n+1||y0==0||y0==m+1||mp[x0][y0]=='x')
    {
        return true;
    }
    return false;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0;
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>mp[i][j];
            }
        }
        for(int i=0;i<=k;i++)
        {
            if(!vis[x][y])
            {
                vis[x][y]=1;
                ans++;
            }
            if(check(x,y,d))
            {
                d=(d+1)%4;
                continue;
            }
            else
            {
                x+=xx[d];
                y+=yy[d];
            }
        }
        cout<<ans<<endl;
    }
}