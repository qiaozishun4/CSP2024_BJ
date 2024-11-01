#include<bits/stdc++.h>
using namespace std;

int n, m, k, sx, sy, d, ans = 0, vis[1005][1005];
int dxy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char a[1005][1005];

void dfs(int x, int y, int step){
    if (step == k+1){
        return;
    }
    //cout<<step<<' ';
    int xx = x + dxy[d][0];
    int yy = y + dxy[d][1];
    if (1 <= x && x <= n && 1 <= y && y <= m && a[xx][yy] == '.'){
        if (vis[xx][yy] == 0) ans++;
        vis[xx][yy] = 1;
        //cout<<xx<<'+'<<yy<<endl;
        dfs(xx, yy, step+1);
    } else {
        d = (d + 1) % 4;
        //cout<<x<<'-'<<y<<endl;
        dfs(x, y, step+1);
    }
    return;
}

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin>>t;
    while (t--){
        cin>>n>>m>>k>>sx>>sy>>d;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        vis[sx][sy] = 1;
        dfs(sx, sy, 1);
        cout<<ans+1<<endl;
        ans = 0;
        memset(vis, 0, sizeof(vis));
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
