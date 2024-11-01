#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char g[1001][1001];
bool vis[1001][1001];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(vis,false,sizeof(vis));
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>g[i][j];
            }
        }
        vis[x][y]=true;
        for(int i=1;i<=k;i++){
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(nx<=n&&ny<=m&&nx>=1&&ny>=1&&g[nx][ny]=='.'){
                x=nx,y=ny;
                vis[x][y]=true;
            }
            else{
                d=(d+1)%4;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}