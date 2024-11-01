#include<iostream>
#include<cstring>
using namespace std;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},n,m,r;
char a[2001][2001];
int vis[2001][2001];
bool f(int x,int y){
    if(x>0&&x<=n&&y>0&&y<=m&&a[x][y]=='.'){
        return 1;
    }
    return 0;
}
void dfs(int x,int y,int d,int i){
    vis[x][y]=1;
    if(i>=r){
        return;
    }
    int xx=x+dx[d],yy=y+dy[d];
    if(f(xx,yy)){
        dfs(xx,yy,d,i+1);
    }
    else{
        dfs(x,y,(d+1)%4,i+1);
    }
}
int main(){
freopen("explore.in","r",stdin);
freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>r;
        int sx,sy,d;
        cin>>sx>>sy>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        dfs(sx,sy,d,0);
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans+=vis[i][j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

