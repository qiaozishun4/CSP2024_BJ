#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,k,ans;
char g[N][N];
void dfs(int x,int y,int d,int t)
{
    if(t==k)
    {
        return ;
    }
    int nx,ny;
    if(d==0)
    {
        nx=x;
        ny=y+1;
    }
    if(d==1)
    {
        nx=x+1;
        ny=y;
    }
    if(d==2)
    {
        nx=x;
        ny=y-1;
    }
    if(d==3)
    {
        nx=x-1;
        ny=y;
    }
    if((nx<1 || nx>n || ny<1 || ny>m) || (g[nx][ny]=='x'))
    {
        dfs(x,y,(d+1)%4,t+1);
        return ;
    }
    ans++;
    dfs(nx,ny,d,t+1);
    return ;
}
void sol()
{
    memset(g,'.',sizeof(g));
    ans=0;
    int cx,cy,cd;
    cin>>n>>m>>k>>cx>>cy>>cd;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cin>>g[i][j];
    }
    if(cd==0 && (g[cx][cy+1]=='x' || cy+1>m)) ans=1;
    if(cd==1 && (g[cx+1][cy]=='x' || cx+1>n)) ans=1;
    if(cd==2 && (g[cx][cy-1]=='x' || cy-1<1)) ans=1;
    if(cd==3 && (g[cx-1][cy]=='x' || cx-1<1)) ans=1;
    dfs(cx,cy,cd,0);
    cout<<ans<<endl;
    return ;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--) sol();
    return 0;
}
