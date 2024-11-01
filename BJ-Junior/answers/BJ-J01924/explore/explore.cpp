#include<bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
bool vis[1005][1005];
char a[1005][1005];
int T;
void dfs(int n,int m,int k,int x,int y,int d){
    int cnt=1;
    vis[x][y]=1;
    for(int i=1;i<=k;i++){
        int nx=x+dx[d],ny=y+dy[d];
        if(nx>0 && nx<=m && ny>0 && ny<=n && a[nx][ny]!='X'){
            x=nx,y=ny;
            if(!vis[x][y]){
                cnt++;
            }
            vis[nx][ny]=1;
        }else{
            d=(d+1)%4;
        }

    }
    cout<<cnt<<"\n";
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                vis[i][j]=0;
            }
        }
        dfs(n,m,k,x,y,d);
    }
    return 0;
}
