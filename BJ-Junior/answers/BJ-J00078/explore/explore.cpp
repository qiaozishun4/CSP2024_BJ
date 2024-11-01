#include<bits/stdc++.h>
using namespace std;

int n,m;
char g[1005][1005];
bool vis[1005][1005];
int mo[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int bfs(int x,int y,int k,int d,int cnt){
    while(k--){
        int nx=x+mo[d][0],ny=y+mo[d][1];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&g[nx][ny]=='.'){
            x=nx,y=ny;
            cnt+=!vis[nx][ny];
            vis[nx][ny]=true;
        }
        else d=(d+1)%4;
    }
    return cnt;
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;cin>>T;
    int x,y,d,k;
    while(T--){
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>g[i][j];
            }
        }
        vis[x][y]=true;
        cout<<bfs(x,y,k,d,1)<<endl;
    }
    return 0;
}
