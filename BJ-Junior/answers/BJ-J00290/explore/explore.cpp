#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 5;
int n, m, k, x, y, d, t;
ll ans;
bool ok[N][N], vis[N][N];
int gox[5] = {0, 1, 0, -1};
int goy[5] = {1, 0, -1, 0};
bool is_in(int xx, int yy){
    if(xx < 0 || xx > n || yy < 0 || yy > m || !ok[xx][yy]) return false;
    return true;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf(" %d",&t);
    while(t--){
        memset(ok, 0, sizeof(ok));
        memset(vis, 0, sizeof(vis));
        ans = 1;
        scanf(" %d %d %d",&n,&m,&k);
        scanf(" %d %d %d",&x,&y,&d);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                char op;
                scanf(" %c",&op);
                if(op == '.') ok[i][j] = true;
            }
        }
        vis[x][y] = true;
        while(k--){
            if(is_in(x+gox[d], y+goy[d])){
                x += gox[d], y += goy[d];
                if(vis[x][y]) continue;
                vis[x][y] = true;
                ans++;
            }
            else{
                d = (d + 1) % 4;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
