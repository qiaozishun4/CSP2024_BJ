#include<iostream>
using namespace std;
int n,m,k,sx,sy,sd;
const int LEN=1e3+5;
char g[LEN][LEN];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void dfs(int x,int y,int d,int cnt)
{
    if(cnt==k)
    {
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(g[i][j]=='*')
                {
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
        return;
    }
    int nx=x+dx[d],ny=y+dy[d];
    if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&g[nx][ny]!='x')
    {
        g[nx][ny]='*';
        dfs(nx,ny,d,cnt+1);
    }
    else
    {
        dfs(x,y,(d+1)%4,cnt+1);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>sx>>sy>>sd;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                cin>>g[i][j];
            }
        }
        g[sx][sy]='*';
        dfs(sx,sy,sd,0);
    }
    return 0;
}
