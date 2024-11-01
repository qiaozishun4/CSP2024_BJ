#include <bits/stdc++.h>

using namespace std;
int t;
int vis[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void dfs(int n,int m,int k,int x,int y,int d){
    if(k<=0){
        return ;
    }
    else{
        k--;
        int xx=x+dx[d];
        int yy=y+dy[d];
        if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&vis[xx][yy]!=-1){
            vis[xx][yy]=1;
            dfs(n,m,k,xx,yy,d);
        }
        else{
            d=(d+1)%4;
            dfs(n,m,k,x,y,d);
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        long long n,m,k,x,y,d,ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j]=0;
                char c;
                cin>>c;
                if(c=='x'){
                    vis[i][j]=-1;
                }
            }
        }
        vis[x][y]=1;
        dfs(n,m,k,x,y,d);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==1){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}