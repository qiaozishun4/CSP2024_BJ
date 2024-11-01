#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,sx,sy,sd,sum=1,dx[5]={0,1,0,-1},dy[5]={1,0,-1,0},vis[1010][1010];
char a[1010][1010];
void dfs(int x,int y,int d,int i1){
    if(i1>k){
        return ;
    }
    int xx=x+dx[d],yy=y+dy[d];
    while(!(xx>0&&yy>0&&xx<=n&&yy<=m)||a[xx][yy]!='.'&&i1<=k){
        d++;
        d%=4;
        xx=x+dx[d];
        yy=y+dy[d];
        i1++;
    }
    if(i1>k){
        return ;
    }
    if(!vis[xx][yy]){
        vis[xx][yy]=1;
        sum++;
    }
    dfs(xx,yy,d,i1+1);
    return ;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        memset(vis,0,sizeof vis);
        sum=1;
        cin>>n>>m>>k>>sx>>sy>>sd;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        dfs(sx,sy,sd,1);
        cout<<sum<<'\n';
    }
    return 0;
}
