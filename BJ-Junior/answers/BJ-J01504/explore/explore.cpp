#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int t, n, m, k, xv;
int ans, yv, dv;
bool vis[1005][1005];
char mp[1005][1005];
int xx[]={0,1,0,-1};
int yy[]={1,0,-1,0};

void dfs(int stp, int x, int y, int d){
    if(stp>k)
        return;
    int dx=x+xx[d], dy=y+yy[d];
    if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&mp[dx][dy]=='.'){
        if(!vis[dx][dy]) ans++;
        vis[dx][dy]=1;
        dfs(stp+1, dx, dy, d);
        return;
    }
    dfs(stp+1, x, y, (1+d)%4);
}

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin>>t;
    for(int e=1;e<=t;e++){
        cin>>n>>m>>k;
        cin>>xv>>yv>>dv;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>mp[i][j];
        memset(vis, 0, sizeof vis);
        ans=1; vis[xv][yv]=1;
        dfs(1, xv, yv, dv);
        cout<<ans<<endl;
    }
    return 0;
}
