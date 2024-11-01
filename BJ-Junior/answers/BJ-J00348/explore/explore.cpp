#include<bits/stdc++.h>
using namespace std;
char g[1100][1100];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int ans=0,cnt=0;
int n,m,k;
void dfs(int x,int y,int d0){
    cnt++;
    if(cnt==(k+1)) return ;
    int nx=x+dx[d0],ny=y+dy[d0];
    if((nx>=1) && (nx<=n) && (ny>=1) && (ny<=m) && (g[nx][ny]=='.')){
        ans++;
        dfs(nx,ny,d0);
    }else{
        int d1=(d0+1)%4;
        dfs(x,y,d1);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int x0,y0,d0;
        cin>>n>>m>>k;
        cin>>x0>>y0>>d0;
        ans=1;
        cnt=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin>>g[i][j];
            }
        }
        dfs(x0,y0,d0);
        cout<<ans<<endl;
    }
    return 0;
}
