//hello world
#include<bits/stdc++.h>
using namespace std;
int t,n,m,K,X,Y,D,dp[1001][1001];
char mp[1001][1001];
void dfs(int x,int y,int d,int k){
    if(k == 0){
        int cnt = 0;
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= m;k++){
                cnt+=dp[j][k];
            }
        }
        cout<<cnt<<endl;
        return;
    }
    if(d == 0){
        if(mp[x][y+1] == '.' && y+1 <= m){
            dp[x][y+1] = 1;
            dfs(x,y+1,d,k-1);
            dp[x][y+1] = 0;
        }
        else{dfs(x,y,1,k-1);}
    }
    else if(d == 1){
        if(mp[x+1][y] == '.' && x+1 <= n){
            dp[x+1][y] = 1;
            dfs(x+1,y,d,k-1);
            dp[x+1][y] = 0;
        }
        else{dfs(x,y,2,k-1);}
    }
    else if(d == 2){
        if(mp[x][y-1] == '.' && y-1 >= 1){
            dp[x][y-1] = 1;
            dfs(x,y-1,d,k-1);
            dp[x][y-1] = 0;
        }
        else{dfs(x,y,3,k-1);}
    }
    else if(d == 3){
        if(mp[x-1][y] == '.' && x-1 >= 1){
            dp[x-1][y] = 1;
            dfs(x-1,y,d,k-1);
            dp[x-1][y] = 0;
        }
        else{dfs(x,y,0,k-1);}
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i = 1;i <= t;i++){
        cin>>n>>m>>K>>X>>Y>>D;
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= m;k++){
                cin>>mp[j][k];
            }
        }
        dp[X][Y] = 1;
        dfs(X,Y,D,K);
    }
    return 0;
}