#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int T;
int n,m,k;
int xx0,yy0,dd0;
int a[N][N];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool vis[N][N];
struct node {int x,y,d,k;};
int ans;

void bfs()
{
    queue <node> q;
    q.push({xx0,yy0,dd0,k});
    while (!q.empty())
    {
        node t=q.front();
        q.pop();
        vis[t.x][t.y]=true;
        if (t.k<=0) continue;

        int xx=t.x+dx[t.d],yy=t.y+dy[t.d];
        if (xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]==1)
        {
            vis[xx][yy]=true;
            q.push({xx,yy,t.d,t.k-1});
        }
        else q.push({t.x,t.y,(t.d+1)%4,t.k-1});
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while (T--)
    {
        ans=0;
        memset(vis,0,sizeof vis);
        cin>>n>>m>>k>>xx0>>yy0>>dd0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                char c;
                cin>>c;
                if (c=='x') a[i][j]=0;
                else a[i][j]=1;
            }
        }
        bfs();
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (vis[i][j]==true) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
