#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
long long n,m,k,xx0,yy0,dd0,ans;
long long nxt[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
long long vis[1005][1005];
void dfs(long long x,long long y,long long k,long long d)
{
    if(k==0)
        return;
    long long xx=x+nxt[d][0];
    long long yy=y+nxt[d][1];
    if(xx>n||xx<=0||yy>m||yy<=0||a[xx][yy]=='x')
    {

        //cout<<x<<' '<<y<<"=="<<endl;
        dfs(x,y,k-1,(d+1)%4);
    }
    else
    {
        if(vis[xx][yy]==0)
            ans++;
        vis[xx][yy]=1;
        //cout<<xx<<' '<<yy<<endl;
        dfs(xx,yy,k-1,d);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long t;
    scanf("%lld",&t);
    while(t--)
    {
        ans=1;
        memset(vis,0,sizeof(vis));
        scanf("%lld %lld %lld\n%lld %lld %lld\n",&n,&m,&k,&xx0,&yy0,&dd0);
        for(long long i=1;i<=n;i++)
        {
            for(long long j=1;j<=m;j++)
                scanf("%c",&a[i][j]);
            scanf("\n");
        }
        vis[xx0][yy0]=1;
        dfs(xx0,yy0,k,dd0);
        cout<<ans<<endl;
    }
    return 0;
}
