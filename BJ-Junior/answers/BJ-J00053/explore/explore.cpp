#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,x,y,d;
char c[1005][1005];
bool vis[1005][1005];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void slv(){
    cin>>n>>m>>k>>x>>y>>d;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>c[i][j];
    vis[x][y]=1;
    while(k--){
        int nx=x+dx[d],ny=y+dy[d];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&c[nx][ny]!='x')x=nx,y=ny,vis[x][y]=1;
        else d++,d%=4;
    }
    int ans=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ans+=vis[i][j],vis[i][j]=0;
    cout<<ans<<endl;
}
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    slv();
    return 0;
}