#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char mat[1010][1010];
int n,m,k,x,y,d,dy[]={1,0,-1,0},dx[]={0,1,0,-1};
bool vis[1010][1010];
void solve(){
    memset(mat,0,sizeof(mat));
    memset(vis,0,sizeof(vis));
    cin>>n>>m>>k>>x>>y>>d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mat[i][j];
        }
    }
    while(k--){
        vis[x][y]=true;
        int nx=x+dx[d],ny=y+dy[d];
        if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&mat[nx][ny]=='.'){
            x=nx,y=ny;
        }
        else d=(d+1)%4;
    }
    vis[x][y]=true;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans+=vis[i][j];
        }
    }
    cout<<ans<<"\n";
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}