#include<bits/stdc++.h>
using namespace std;
int n,m,k,T,x,y,d,ans,v[1005][1005];
char a[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int x,int y,int d,int k,int ans)
{
    if(k==0)
    {
        cout<<ans<<endl;
        return ;
    }
    int nx=x+dx[d],ny=y+dy[d];
    if(nx<1||nx>n||ny<1||ny>m||v[nx][ny]==0) return dfs(x,y,(d+1)%4,k-1,ans);
    if(v[nx][ny]==1)
    {
        v[nx][ny]=2;
        return dfs(nx,ny,d,k-1,ans+1);
    }
    return dfs(nx,ny,d,k-1,ans);

}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        int ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='x') v[i][j]=0;
                else v[i][j]=1;
            }
        }

        dfs(x,y,d,k,1);
    }
    return 0;
}