#include<bits/stdc++.h>
using namespace std;

long long n, m, k, x, y, z, mod = 4, T, cnt = 1;
bool vis[1010][1010];
long long dx[5] = {0, 1, 0, -1};
long long dy[5] = {1, 0, -1, 0};
char a[1010][1010];

void dfs(long long d, long long b, long long c){
    if(k == 0){
        return;
    }
    k--;
    long long tx = d+dx[c], ty = b+dy[c];
    if(tx >= 1 && ty <= m && tx <= n && ty >= 1 && a[tx][ty] == '.'){
        if(vis[tx][ty] == 0){
            cnt++;
        }
        vis[tx][ty] = 1;
        dfs(tx,ty,c);
        vis[tx][ty] = 0;
    }else{
        long long p = (c+1) % mod;
        dfs(d,b,p);
    }
}


int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>k>>x>>y>>z;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin>>a[i][j];
            }
        }
        vis[x][y] = 1;
        dfs(x, y, z);
        cout<<cnt<<endl;
        vis[x][y] = 0;
        cnt = 1;
    }
    return 0;
}