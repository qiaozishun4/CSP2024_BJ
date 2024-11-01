#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool mp[1005][1005],vis[1005][1005];
void dfs(int x,int y,int d,int k)
{
    vis[x][y]=1;
    if(k==0)return ;
    int nx=x,ny=y;
    if(d==0)ny++;
    else if(d==1)nx++;
    else if(d==2)ny--;
    else nx--;
    if(mp[nx][ny])dfs(x,y,(d+1)%4,k-1);
    else dfs(nx,ny,d,k-1);
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        memset(mp,1,sizeof(mp));
        memset(vis,0,sizeof(vis));
        int n,m,k,x,y,d,i,j,cnt=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                char c;
                cin>>c;
                if(c=='x')mp[i][j]=1;
                else mp[i][j]=0;
            }
        }
        dfs(x,y,d,k);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(vis[i][j])cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
