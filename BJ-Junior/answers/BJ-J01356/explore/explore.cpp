#include <bits/stdc++.h>

using namespace std;

int t,n,m,k,xx,yy,d,ans,cnt;
char c;
bool a[1005][1005];
bool vis[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int x,int y,int d)
{
    if(cnt>k)return;
    cnt++;
    if(!vis[x][y]){ans++;vis[x][y]=1;}
    int px=x+dx[d],py=y+dy[d];
    if(px>=1&&py>=1&&px<=n&&py<=m&&!a[px][py])
    {
        dfs(px,py,d);
    }
    else
    {
        dfs(x,y,(d+1)%4);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0,cnt=0;
        memset(a,false,sizeof(a));
        memset(vis,false,sizeof(vis));
        cin>>n>>m>>k>>xx>>yy>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                cin>>c;
                if(c=='.')a[i][j]=0;
                else a[i][j]=1;
            }
        dfs(xx,yy,d);
        cout<<ans<<endl;
    }
    return 0;
}
