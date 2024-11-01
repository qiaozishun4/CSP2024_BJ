#include<bits/stdc++.h>
using namespace std;
int cnt=0,n,m,k;
int x,y,d;
char a[1001][1001];
bool vis[1001][1001][4];
void solve(){
    cnt=1;
    memset(vis,0,sizeof(vis));
    cin>>n>>m>>k;
    cin>>x>>y>>d;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for (int i=1;i<=k;i++){
        vis[x][y][d]=1;
        if (d==0){
            int nx=x;
            int ny=y+1;
            if (nx<1||ny<1||nx>n||ny>m||a[nx][ny]=='x'){
                d=(d+1)%4;
                continue;
            }
            if (!vis[nx][ny][d])cnt++;
            x=nx;y=ny;
        }else if (d==1){
            int nx=x+1;
            int ny=y;
            if (nx<1||ny<1||nx>n||ny>m||a[nx][ny]=='x'){
                d=(d+1)%4;
                continue;
            }
            if (!vis[nx][ny][d])cnt++;
            x=nx;y=ny;
        }else if (d==2){
            int nx=x;
            int ny=y-1;
            if (nx<1||ny<1||nx>n||ny>m||a[nx][ny]=='x'){
                d=(d+1)%4;
                continue;
            }
            if (!vis[nx][ny][d])cnt++;
            x=nx;y=ny;
        }else if (d==3){
            int nx=x-1;
            int ny=y;
            if (nx<1||ny<1||nx>n||ny>m||a[nx][ny]=='x'){
                d=(d+1)%4;
                continue;
            }
            if (!vis[nx][ny][d])cnt++;
            x=nx;y=ny;
        }

    }
    cout<<cnt<<endl;
}
int T;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while (T--){
        solve();
    }
    return 0;
}
