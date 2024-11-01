#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,d,cur;
};
queue<node> q;
char a[1005][1005];
bool vis[1005][1005];
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int T,n,m,k,x,y,d;
/*
void dfs(int x,int y,int d,int cur)
{
    vis[x][y]=1;
    if(cur==k)
    {
        return ;
    }
    //cout<<x<<" "<<y<<" "<<d<<" "<<cur<<endl;
    int nx=x+dx[d];
    int ny=y+dy[d];
    if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='x')
    {
        dfs(x,y,(d+1)%4,cur+1);
    }
    else
    {
        dfs(nx,ny,d,cur+1);
    }
}
*/
void bfs(int x,int y,int d,int cur)
{
    q.push({x,y,d,0});
    while(q.front().cur<=cur)
    {
        //cout<<q.front().x<<" "<<q.front().y<<" "<<q.front().d<<" "<<q.front().cur<<endl;
        vis[q.front().x][q.front().y]=1;
        int nx=q.front().x+dx[q.front().d];
        int ny=q.front().y+dy[q.front().d];
        if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='x')
        {
            q.push({q.front().x,q.front().y,(q.front().d+1)%4,q.front().cur+1});
        }
        else
        {
            q.push({nx,ny,q.front().d,q.front().cur+1});
        }
        q.pop();
    }
    while(!q.empty())
    {
        q.pop();
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                vis[i][j]=0;
            }
        }
        bfs(x,y,d,k);
        long long cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(vis[i][j])
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
