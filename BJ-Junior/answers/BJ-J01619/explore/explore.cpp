#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int xc,yc;
int d;
int cnt=1;
int kk=0;
bool vis[1005][1005];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
char mp[1005][1005];
void dfs(int x,int y)
{
    if(kk>=k)
    {
        cout<<cnt<<"\n";
        return ;
    }
    kk++;
    int nx=x+dx[d];
    int ny=y+dy[d];
    if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.')
    {
        if(!vis[nx][ny])
        {
            cnt++;
        }
        vis[nx][ny]=1;
        dfs(nx,ny);
    }
    else
    {
        d=(d+1)%4;
        dfs(x,y);
    }
    return ;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cnt=1;
        kk=0;
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>xc>>yc>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>mp[i][j];
            }
        }
        vis[xc][yc]=1;
        dfs(xc,yc);
    }
    return 0;
}
