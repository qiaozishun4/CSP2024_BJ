#include<bits/stdc++.h>
using namespace std;
long long n,m,k,t,sx,sy,sd,ans=0;
bool mp[1005][1005];
bool vis[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void reset()
{
    ans=0;
    for(int i=0;i<1005;i++)
    {
        for(int j=0;j<1005;j++)
        {
            mp[i][j]=0;
            vis[i][j]=0;
        }
    }
}

void dfs(int x,int y,int d)
{
    //cout<<x+1<<y+1<<d<<endl;
    if(k==0)
    {
        vis[x][y]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //cout<<vis[i][j]<<" ";
                if(vis[i][j])
                {
                    ans++;
                }
            }
            //cout<<endl;
        }
        return;
    }
    int nx=x+dx[d];
    int ny=y+dy[d];
    if(nx>=0&&nx<n&&ny>=0&&ny<m&&!mp[nx][ny])
    {
        vis[x][y]=1;
        k--;
        dfs(nx,ny,d);
    }
    else
    {
        k--;
        dfs(x,y,(d+1)%4);
    }
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        reset();
        cin>>n>>m>>k;
        cin>>sx>>sy>>sd;
        sx--;
        sy--;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<m;j++)
            {
                if(s[j]=='x') mp[i][j]=1;
            }
        }
        vis[sy][sx]=1;
        dfs(sx,sy,sd);
        cout<<ans<<endl;
    }
    return 0;
}
