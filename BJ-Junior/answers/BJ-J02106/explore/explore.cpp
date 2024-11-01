#include<bits/stdc++.h>
using namespace std;
int cnt=1;
int dx[5]={0,1,0,-1};
int dy[5]={1,0,-1,0};
int vis[1002][1002]={};
char a[1002][1002]={};
int t,n,m,k;
int x,y,d;
void dfs(int x,int y,int d,int s){
    if(s==0)return;
    else{
        int nx=x+dx[d];
        int ny=y+dy[d];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.'){
            if(vis[nx][ny]==0)cnt++;
            vis[x][y]=1;
            dfs(nx,ny,d,s-1);
        }else{
            d=(d+1)%4;
            vis[x][y]=1;
            dfs(x,y,d,s-1);
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)cin>>a[i][j];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j]=0;
            }
        }
        cnt=1;
        vis[x][y]=1;
        dfs(x,y,d,k);
        cout<<cnt<<endl;
    }
    return 0;
}
