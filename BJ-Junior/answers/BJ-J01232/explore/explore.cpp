#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,ans;
int x,y,d;
char w[1010][1010];
bool vis[1010][1010];
bool check(int x,int y){
    if(x<=0||y<=0||x>n||y>m||w[x][y]=='x'){
        return false;
    }
    return true;
}
inline void dfs(int x,int y,int d,int k){
    if(!vis[x][y]){
        ans++;
        vis[x][y]=true;
    }
    if(k<=0){
        return;
    }
    if(d==0){
        if(check(x,y+1)){
            dfs(x,y+1,d,k-1);
        }
        else{
            int z=(d+1)%4;
            dfs(x,y,z,k-1);
        }
    }
    else if(d==1){
        if(check(x+1,y)){
            dfs(x+1,y,d,k-1);
        }
        else{
            int z=(d+1)%4;
            dfs(x,y,z,k-1);
        }
    }
    else if(d==2){
        if(check(x,y-1)){
            dfs(x,y-1,d,k-1);
        }
        else{
            int z=(d+1)%4;
            dfs(x,y,z,k-1);
        }
    }
    else if(d==3){
        if(check(x-1,y)){
            dfs(x-1,y,d,k-1);
        }
        else{
            int z=(d+1)%4;
            dfs(x,y,z,k-1);
        }
    }
    return;
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
                vis[i][j]=false;
                cin>>w[i][j];
            }
        }
        ans=0;
        dfs(x,y,d,k);
        cout<<ans<<endl;
    }
    return 0;
}
