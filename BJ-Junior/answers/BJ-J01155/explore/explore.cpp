#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans;
char a[1005][1005];
bool vis[1005][1005];

void dfs(int x,int y,int d,int k){
    if(k==0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==1){
                    vis[i][j]==0;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
        return;
    }
    k--;
    if(d==0){
        if(x>0 && x<=n && y+1>0 && y+1<=m && a[x][y+1]=='.'){
            vis[x][y+1]=1;
            dfs(x,y+1,0,k);
        }
        else dfs(x,y,1,k);
    }
    else if(d==1){
        if(x+1>0 && x+1<=n && y>0 && y<=m && a[x+1][y]=='.'){
            vis[x+1][y]=1;
            dfs(x+1,y,1,k);
        }
        else dfs(x,y,2,k);
    }
    else if(d==2){
        if(x>0 && x<=n && y-1>0 && y-1<=m && a[x][y-1]=='.'){
            vis[x][y-1]=1;
            dfs(x,y-1,2,k);
        }
        else dfs(x,y,3,k);
    }
    else{
        if(x-1>0 && x-1<=n && y>0 && y<=m && a[x-1][y]=='.'){
            vis[x-1][y]=1;
            dfs(x-1,y,3,k);
        }
        else dfs(x,y,0,k);
    }
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        vis[x][y]=1;
        ans=0;
        dfs(x,y,d,k);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j]=vis[i][j]=0;
            }
        }
    }
    return 0;
}
