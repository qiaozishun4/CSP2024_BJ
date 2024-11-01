#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,d,x,y,ans;
char g[1005][1005];
bool vis[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int x,int y,int d){
    if(k==0) return ;
    for(int i=0;i<4;i++){
        int nx=x+dx[(d+i)%4],ny=y+dy[(d+i)%4];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&vis[nx][ny]==0&&g[nx][ny]!='x'){
            vis[nx][ny]=1;
            k--;
            ans++;
            dfs(nx,ny,(d+i)%4);
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","r",stdout);
    cin>>T;
    while(T--){
        memset(vis,sizeof(vis),0);
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>g[i][j];
            }
        }
        vis[x][y]=1;
        dfs(x,y,d);
        cout<<ans;
        ans=1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}