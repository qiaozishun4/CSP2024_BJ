#include<bits/stdc++.h>
using namespace std;
int n,m,k,dx[6]={0,1,0,-1},dy[6]={1,0,-1,0},ans;
char a[1005][1005];
bool vis[1005][1005];
void dfs(int x,int y,int d){
    vis[x][y]=true;
    while(k--){
        int xx=x+dx[d];
        int yy=y+dy[d];
        if(xx<=n&&xx>=1&&yy<=m&&yy>=1&&a[xx][yy]=='.'){
            x=xx,y=yy;
            vis[xx][yy]=true;
        }
        else{
            d=(d+1)%4;
        }
    }
}
void solve(){
    scanf("%d%d%d",&n,&m,&k);
    int x0,y0,d;
    scanf("%d%d%d",&x0,&y0,&d);
    for(int i=1;i<=n;i++){
        scanf("%s",a[i]+1);
    }
    dfs(x0,y0,d);
    ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vis[i][j])ans++,vis[i][j]=false;
        }
    }
    printf("%d\n",ans);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
