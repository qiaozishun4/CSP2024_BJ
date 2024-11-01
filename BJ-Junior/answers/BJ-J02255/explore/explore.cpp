#include <iostream>
#include <cstring>
#define maxn int(1e3+5)
#define endl "\n"
using namespace std;
char a[maxn][maxn];
bool vis[maxn][maxn];
const int d1[]={0,1,0,-1},d2[]={1,0,-1,0};
void solve()
{
    int n,m,k,x,y,d,ans=1;
    memset(vis,0,sizeof(vis));
    cin>>n>>m>>k>>x>>y>>d;
    vis[x][y]=true;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
    while(k--)
    {
        int xx=x+d1[d],yy=y+d2[d];
        if(xx<=n&&yy<=m&&xx>0&&yy>0&&a[xx][yy]!='x')x=xx,y=yy;
        else d=(d+1)%4;
        if(!vis[x][y])++ans,vis[x][y]=true;
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}
