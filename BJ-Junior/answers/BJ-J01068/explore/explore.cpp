#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
char g[N][N];
bool vis[N][N];
int ans[N];
int n, m, k;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool check(int x, int y){
    if(x<1||x>n||y<1||y>m||g[x][y]=='x') return false;
    return true;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T, pw = 0;
    cin >> T;
    for(int a1 = 1; a1<=T; a1++){
        memset(vis, false, sizeof(vis));
        int q, e, z;
        cin >> q >> e >> z;
        n = q, m = e, k = z;
        int x, y, d;
        cin >> x >> y >> d;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                cin >> g[i][j];
            }
        }
        vis[x][y] = true;
        for(int i = 1; i<=k; i++){
            if(!check(x+dx[d], y+dy[d])){
                d = (d+1)%4;
                continue;
            }
            x = x+dx[d], y = y+dy[d];
            vis[x][y] = true;
        }
        int sum = 0;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(vis[i][j]){
                    sum++;
                }
            }
        }
        pw++;
        ans[pw] = sum;
    }
    for(int i = 1; i<=pw; i++){
        cout << ans[pw] << endl;
    }
    return 0;
}
