#include<bits/stdc++.h>
using namespace std;
const long long N=1e3+10;
long long T,n,m,k,sx,sy,d,ans;
long long px[]={0,1,0,-1};
long long py[]={1,0,-1,0};
char a[N][N];
bool vis[N][N];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        memset(vis,false,sizeof(vis));
        ans=0;
        cin>>n>>m>>k>>sx>>sy>>d;
        for(long long i=1;i<=n;i++) for(long long j=1;j<=m;j++) cin>>a[i][j];
        vis[sx][sy]=true;
        for(long long i=1;i<=k;i++)
        {
            long long fx,fy;
            fx=sx+px[d];
            fy=sy+py[d];
            if(fx>=1 && fx<=n && fy>=1 && fy<=m && a[fx][fy]=='.')
            {
                vis[fx][fy]=true;
                sx=fx;
                sy=fy;
            }
            else d=(d+1)%4;
        }
        for(long long i=1;i<=n;i++) for(long long j=1;j<=m;j++) ans+=vis[i][j];
        cout<<ans<<endl;
    }
    return 0;
}
