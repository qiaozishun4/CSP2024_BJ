#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
int t,n,m,k,x,y,d,ans=0,cnt=0,flag=0;
char a[N][N];
int vis[N][N];
int dx[10]={0,1,0,-1};
int dy[10]={1,0,-1,0};
void dfs(int x,int y,int d)
{
    if(vis[x][y]==0) ans++;
    vis[x][y]=1;
    if(cnt==k)
    {
        flag=1;
        return;
    }
    for(int i=0;i<=3;i++)
    {
        int nd=(d+i)%4;
        int nx=x+dx[nd];
        int ny=y+dy[nd];
        if(nx>n||nx<1||ny>m||ny<1||a[nx][ny]=='x')
        {
            cnt++;
            if(cnt==k)
            {
                flag=1;
                return;
            }
            continue;
        }
        cnt++;
        dfs(nx,ny,nd);
        if(flag==1) return;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) cin>>a[i][j];
        }
        memset(vis,0,sizeof(vis));
        ans=0;
        cnt=0;
        flag=0;
        dfs(x,y,d);
        cout<<ans<<"\n";
    }
    return 0;
}
