#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+7;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
char mp[N][N];
bool vis[N][N];
int x,y,d;
int n,m,k;
inline void rot(){d++;d%=4;}
inline void slv(){
    cin>>n>>m>>k;
    cin>>x>>y>>d;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>mp[i][j],vis[i][j]=0;
    for(int i=1;i<=m;i++)mp[0][i]=mp[n+1][i]='x';
    for(int i=1;i<=n;i++)mp[i][0]=mp[i][m+1]='x';
    for(int i=1;i<=k;i++){
        vis[x][y]=1;
        int nx=x+dx[d],ny=y+dy[d];
        if(mp[nx][ny]=='x')rot();
        else x=nx,y=ny;
    }
    vis[x][y]=1;
    int ans=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ans+=vis[i][j];
    cout<<ans<<endl;
    return;
}
signed main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--)slv();
    cout.flush();
    return 0;
}