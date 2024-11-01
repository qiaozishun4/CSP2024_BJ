#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int T,n,m,k;
int x,y,d,ans;
char s[N][N];
bool vis[N]={true};
int dfs(int x,int y)
{
    int cnt;
    k--;
    for(int i=1;i<=4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<1||xx>n||yy<1||yy>m||vis[i]!=true) continue;
        if(k<=0) return cnt;
        if(s[xx][yy]!='x')
            yy--;
        if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&vis[i]!=false&&s[xx][yy]!='x'&&k!=0)
        {
            dfs(xx,yy);
            vis[i]=false;
            ans++;
        }
    }
}
signed main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>s[i][j];
                ans=dfs(i,j);
            }
        }
    }
    cout<<ans;
    return 0;
}
