#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
char c[N][N];
long long sx,sy,d,n,m,k;
bool vis[N][N];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void dfs(int x,int y,int cnt)
{
    //cout<<x<<" "<<y<<" "<<cnt<<" "<<d<<endl;
    if(cnt>k) return ;
    vis[x][y]=1;
    int nx=x+dx[d];
    int ny=y+dy[d];
    while(nx<1 || nx>n || ny<1 || ny>m || c[nx][ny]=='x')
    {
        d=(d+1)%4;
        nx=x+dx[d],ny=y+dy[d];
        cnt++;
        if(cnt>k) return ;
    }
    cnt++;
    dfs(nx,ny,cnt);
    return ;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                vis[i][j]=0;
            }
        }
        cin>>n>>m>>k;
        cin>>sx>>sy>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c[i][j];
                if(c[i][j]=='x') flag=false;
            }
        }
        d%=4;
        dfs(sx,sy,0);
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(vis[i][j]) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
