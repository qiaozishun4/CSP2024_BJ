#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;
int n,m,k,qx,qy,fx;
char c[N][N];
bool vis[N][N];
bool hs[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct Node
{
    int x,y;
    int f;
};
int cnt;
int ans;
int lsbl;
bool flag=0;
void dfs(int x,int y,int f)
{
    queue<Node> q;
    q.push({x,y});
    vis[x][y]=1;
    while(!q.empty())
    {
        Node now=q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {
            lsbl++;
            if(cnt==k)
                return;

            int nx=now.x+dx[f];
            int ny=now.y+dy[f];
            if(nx<=n&&nx>0&&ny<=m&&ny>0&&c[nx][ny]!='x')
            {
                if(lsbl==1)
                    flag=1;
                cnt++;
                q.push({nx,ny});
                hs[nx][ny]=1;
                vis[nx][ny]=1;
                break;
            }
            f=(f+1)%4;
            cnt++;
        }
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        memset(c,' ',sizeof(c));
        memset(hs,0,sizeof(hs));
        ans=0;
        cnt=0;
        lsbl=0;
        flag=0;
        cin>>n>>m>>k;
        cin>>qx>>qy>>fx;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c[i][j];
            }
        }
        dfs(qx,qy,fx);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(hs[i][j])
                    ans++;
            }
        }
        cout<<ans+1<<'\n';
    }
    return 0;
}
