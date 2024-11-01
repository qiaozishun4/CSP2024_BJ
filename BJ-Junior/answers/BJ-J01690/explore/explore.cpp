#include <bits/stdc++.h>
using namespace std;
const int N=3005;
const int f[5][5]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m,k,sx,sy,sd;
char ch[N][N];
bool vis[N][N];
void work(){
    vis[sx][sy]=1;
    while(k--){
        int nx=sx+f[sd][0],ny=sy+f[sd][1];
        if(nx<1 || nx>n || ny<1 || ny>m || ch[nx][ny]=='x'){
            sd=(sd+1)%4;
        }else{
            sx=nx;
            sy=ny;
            vis[sx][sy]=1;
        }
    }
}
void solve(){
    memset(ch,',',sizeof(ch));
    memset(vis,false,sizeof(vis));
    cin >>n>>m>>k>>sx>>sy>>sd;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >>ch[i][j];
        }
    }
    work();
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans+=(vis[i][j]==true);
        }
    }
    cout <<ans<<endl;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >>t;
    while(t--){
        solve();
    }
    return 0;
}
