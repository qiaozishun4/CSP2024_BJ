#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
const int M=1e3;
int T,n,m,k,a[N][M],dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},vis[N][M];
void dfs(int x,int y,int d,int kp){
    if(kp==k){
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==1)cnt++;
            }
        }
        cout<<cnt<<endl;
        return ;
    }
    int xx=x+dx[d];
    int yy=y+dy[d];
    if(a[xx][yy]==0&&xx>=1&&xx<=n&&yy>=1&&yy<=m){
        vis[xx][yy]=1;
        dfs(xx,yy,d,kp+1);
    }
    else{
        dfs(x,y,(d+1)%4,kp+1);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        cin>>n>>m>>k;
        int x0,y0,d0;
        cin>>x0>>y0>>d0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char sr;
                cin>>sr;
                if(sr=='.') a[i][j]=0;
                else a[i][j]=1;
            }
        }
        vis[x0][y0]=1;
        dfs(x0,y0,d0,0);
    }
    return 0;
}
