#include<bits/stdc++.h>
using namespace std;
int t,ans,n,m,k,x,y,d,vis[1010][1010];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
char a[1010][1010];
void dfs(int xa,int ya,int da,int cnt)
{
    if(cnt>k) return;
    int w=0;
    while((a[xa+dx[da]][ya+dy[da]]=='x'||xa+dx[da]>n||xa+dx[da]<1||ya+dy[da]>m||ya+dy[da]<1)&&(w<5)) da=(da+1)%4,cnt++,w++;
    //cout<<xa<<" "<<ya<<"\n";
    if(cnt>k) return;
    if(vis[xa+dx[da]][ya+dy[da]]==0&&a[xa+dx[da]][ya+dy[da]]=='.') ans++,dfs(xa+dx[da],ya+dy[da],da,cnt+1);
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0,memset(vis,0,sizeof(vis));
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
        dfs(x,y,d,1);
        cout<<ans+1<<"\n";
    }
    return 0;
}
