#ifndef EXPLORE_CPP_INCLUDED
#define EXPLORE_CPP_INCLUDED
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
char mp[maxn][maxn];
int vis[maxn][maxn];
int T;
int n, m, k;
int st, ed, d;
int ans = 1;
bool check(int x, int y){
    return x>=1 && x<=n && y>=1 && y<=m;
}
void dfs(int x, int y, int d, int dep){
    if(dep == k-1) return;
    if(d == 0){//dong
        if(vis[x][y+1] == -1 || !check(x, y+1)){
            d = (d+1)%4;
            dfs(x, y, d, dep+1);
        }
        else{
            if(vis[x][y+1] == 0){
                ans++;
                vis[x][y+1] = 1;
            }
            dfs(x, y+1, d, dep+1);
        }
    }
    if(d == 1){//nan
        if(vis[x+1][y] == -1 || !check(x+1, y)){
            d = (d+1)%4;
            dfs(x, y, d, dep+1);
        }
        else{
            if(vis[x+1][y] == 0){
                ans++;
                vis[x+1][y] = 1;
            }
            dfs(x+1, y, d, dep+1);
        }
    }
    if(d == 2){
        if(vis[x][y-1] == -1 || !check(x, y-1)){
            d = (d+1)%4;
            dfs(x, y, d, dep+1);
        }
        else{
            if(vis[x][y-1] == 0){
                ans++;
                vis[x][y-1] = 1;
            }
            dfs(x, y-1, d, dep+1);
        }
    }
    if(d == 3){
        if(vis[x-1][y] == -1 || !check(x-1, y)){
            d = (d+1)%4;
            dfs(x, y, d, dep+1);
        }
        else{
            if(vis[x-1][y] == 0){
                ans++;
                vis[x-1][y] = 1;
            }
            dfs(x-1, y, d, dep+1);
        }
    }
}
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin>>T;
    while(T--){
        memset(vis, 0, sizeof(vis));
        ans = 1;
        cin>>n>>m>>k;
        cin>>st>>ed>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
                if(mp[i][j] == 'x') vis[i][j] = -1;
            }
        }
        vis[st][ed] = 1;
        dfs(st, ed, d, 0);
        cout<<ans<<endl;
    }
    return 0;
}

#endif // EXPLORE_CPP_INCLUDED
