#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,dir,vis[1010][1010];
char a[1010][1010];
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int cnt=0;
        cin>>n>>m>>k>>x>>y>>dir;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j]=0;
                cin>>a[i][j];
            }
        }
        vis[x][y]=1;
        while(k--){
            int nx=x+dx[dir],ny=y+dy[dir];
            if(nx<1 || nx>n || ny<1 || ny>m || a[nx][ny]=='x') dir=(dir+1)%4;
            else{
                x=nx,y=ny;
                vis[x][y]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==1) cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
