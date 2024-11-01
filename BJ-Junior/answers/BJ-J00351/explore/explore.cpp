#include <bits/stdc++.h>
using namespace std;
int n,m,d,k,x,y,nx,ny,q;
char mp[1005][1005];
int vis[1005][1005];
int ans[10000005];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void rb(){
    vis[x][y]=1;
    nx=x+dx[d];
    ny=y+dy[d];
    if(mp[nx][ny]=='.'){
        x=nx;
        y=ny;
    }
    else d=(d+1)%4;
    vis[x][y]=1;
    return ;
}
int expf(){
    int cnt=0;
    for(int i=1;i<=k;i++) rb();
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            if(vis[i][j]==1){
                cnt++;
                mp[i][j]=' ';
                vis[i][j]=0;
            }
        }
    }
    return cnt;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>q;
    for(int l=1;l<=q;l++){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        ans[l]=expf();
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
    return 0;
}