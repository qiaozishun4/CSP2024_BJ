#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
char a[N][N];
bool vis[N][N];
int t,cnt;
int n,m,k;
int dfs(int x,int y,int d){
    if(t==k){
        return cnt;
    }
    int xx=x,yy=y;
    if(d==0){
        xx=x;
        yy=y+1;
    }
    if(d==1){
        xx=x+1;
        yy=y;
    }
    if(d==2){
        xx=x;
        yy=y-1;
    }
    if(d==3){
        xx=x-1;
        yy=y;
    }
    if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]=='.'){
        if(vis[xx][yy]==0){
            vis[xx][yy]=1;
            cnt++;
        }
        t++;
        dfs(xx,yy,d);
    }else{
        int dd=(d+1)%4;
        t++;
        dfs(x,y,dd);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        int sx,sy,sd;
        cin>>sx>>sy>>sd;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        cnt=1;
        t=0;
        vis[sx][sy]=1;
        int ans=dfs(sx,sy,sd);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}