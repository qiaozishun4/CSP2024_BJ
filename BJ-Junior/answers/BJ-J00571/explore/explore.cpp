#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int T,n,m;char a[N][N];bool vis[N][N];
inline void solve(int &x,int &y,int &d)
{
    int tmpx=x+(d==1?1:(d==3?-1:0)),tmpy=y+(d==0?1:(d==2?-1:0));
    if(tmpx>=1&&tmpx<=n&&tmpy>=1&&tmpy<=m&&a[tmpx][tmpy]=='.') x=tmpx,y=tmpy;
    else d=(d+1)%4;
}
int main()
{
    freopen("explore.in","r",stdin);freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        memset(vis,false,sizeof(vis));
        int k,sx,sy,sd,ans=0;cin>>n>>m>>k>>sx>>sy>>sd;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
        vis[sx][sy]=true;for(int i=1,x=sx,y=sy,d=sd;i<=k;i++) solve(x,y,d),vis[x][y]=true;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans+=vis[i][j];cout<<ans<<endl;
    }
    return 0;
}