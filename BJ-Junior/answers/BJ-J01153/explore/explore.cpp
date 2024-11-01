#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb emplace_back
ll n,m,k,sx,sy,d,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},vis[1005][1005];
void dfs(int x,int y){
    if(k<0)return;
    vis[x][y]=1;
    int nx=x+dx[d],ny=y+dy[d];
    while(vis[nx][ny]==-1){
        d++,d%=4,nx=x+dx[d],ny=y+dy[d],k--;
        if(k<0)return;
    }
    k--;
    dfs(nx,ny);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(vis,0,sizeof vis);
        ll ans=0;
        cin>>n>>m>>k>>sx>>sy>>d;
        for(int i=1;i<=n;i++)vis[i][0]=vis[i][m+1]=-1;
        for(int j=1;j<=m;j++)vis[0][j]=vis[n+1][j]=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char a;
                cin>>a;
                if(a=='x')vis[i][j]=-1;
            }
        }
        dfs(sx,sy);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==1)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
