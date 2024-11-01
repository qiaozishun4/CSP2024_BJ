#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
long long T,n,m,k,sx,sy,sd,ans=0;
long long dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char a[1005][1005];
bool vis[1005][1005];
void dfs(long long p,long long x,long long y,long long d)
{
    if(p>k)
    {
        return ;
    }
    long long nx=x+dx[d],ny=y+dy[d];
    if(nx<1 || nx>n || ny<1 || ny>m || a[nx][ny]!='.')
    {
        dfs(p+1,x,y,(d+1)%4);
    }
    else
    {
        if(!vis[nx][ny])
        {
            ++ans;
            vis[nx][ny]=true;
        }
        dfs(p+1,nx,ny,d);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&n,&m,&k);
        scanf("%lld%lld%lld",&sx,&sy,&sd);
        for(int i=1;i<=n;++i)
        {
            cin>>a[i][1];
            vis[i][1]=false;
            for(int j=2;j<=m;++j)
            {
                scanf("%c",&a[i][j]);
                vis[i][j]=false;
            }
        }
        ans=1;
        vis[sx][sy]=true;
        dfs(1,sx,sy,sd);
        printf("%lld\n",ans);
    }
    return 0;
}