#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0},vis[1005][1005];
int n,m,anss;
int dfs(int x,int y,int k,int d,int ans)
{
    if(k<=0) return ans;
    vis[x][y]=1;
    int nx=x+dx[d],ny=y+dy[d];
    if(a[nx][ny]=='x' || nx>n || nx<0 || ny>m || ny<0 || vis[nx][ny])
    {
        anss=max(anss,dfs(x,y,k-1,d+1%4,ans));
    }
    else
    {
        //anss=max(anss,dfs(x,y,k-1,d+1%4,ans));
        anss=max(anss,dfs(nx,ny,k-1,d,ans+1));
    }
    vis[x][y]=0;
    return ans;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    int x,y,k,d;
    while(t--)
    {
        anss=1;
        memset(a,'\0',sizeof(a));
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        dfs(x,y,k,d,anss);
        cout<<anss<<endl;
    }


}
