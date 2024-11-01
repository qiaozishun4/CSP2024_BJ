#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
bool vis[1001][1001];
int b[4]={0,1,0,-1};
int c[4]={1,0,-1,0};
int n,m,k,x,y,d;
int l=1;
int dfs(int x,int y,int k,int l,int d){
    if(k==0){
        return l;
    }
    int xx=x+b[d];
    int yy=y+c[d];
    if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]=='.'){
        if(vis[xx][yy]==0){
            vis[x][y]=1;
            dfs(xx,yy,k-1,l+1,d);
        }else dfs(xx,yy,k-1,l,d);
    }else dfs(x,y,k-1,l,((d+1)%4));
}
int main(){
    freopen("explore.in","r",stdin);
   freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        cout<<dfs(x,y,k,l,d);
    }
fclose(stdin);
fclose(stdout);
    return 0;
}
