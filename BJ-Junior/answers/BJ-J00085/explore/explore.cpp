#include <bits/stdc++.h>
using namespace std;
int g[1005][1005];
int vis[1005][1005];
int p[4][3] = {{0,1},{1,0},{0,-1},{-1,0}};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,k,xa,ya,d;
        cin>>n>>m>>k;
        cin>>xa>>ya>>d;
        memset(g,0,sizeof(g));
        memset(vis,0,sizeof(vis));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                char t;
                cin>>t;
                if(t == '.'){
                    g[i][j] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= k; i++){
            if(!vis[xa][ya]){
                ans++;
                vis[xa][ya] = 1;
            }
            int nx = xa+p[d][0], ny = ya+p[d][1];
            if(nx <= n && nx >= 1 && ny <= m && ny >= 1 && g[nx][ny]){
                xa = nx, ya = ny;
            }else{
                 d = (d+1)%4;
            }
            //cout<<xa<<' '<<ya<<' '<<d<<endl;
            if(!vis[xa][ya]){
                ans++;
                vis[xa][ya] = 1;
            }
        }
        cout<<ans<<endl;
    }
}
