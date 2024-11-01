#include<bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

char mp[1010][1010];
int vis[1010][1010];

void dfs(int x, int y, int d, int k, int n, int m){
    k++;
    while(k){
        //cout << x << ' ' << y << '\n';
        vis[x][y] = 1;
        /*if(k == 0){
            return;
        }*/
        int x1 = x+dx[d], y1 = y+dy[d];
        if(x1 > n || y1 > m || x1 < 1 || y1 < 1){
            //dfs(x, y, (d+1)%4, k-1, n, m);
            d = (d+1)%4;
        }else if(mp[x1][y1] == 'x'){
            //dfs(x, y, (d+1)%4, k-1, n, m);
            d = (d+1)%4;
        }else{
            //dfs(x1, y1, d, k-1, n, m);
            x = x1; y = y1;
        }
        k--;
    }
    return;
}

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int n, m, k;
        int x0, y0, d0;
        cin >> n >> m >> k;
        cin >> x0 >> y0 >> d0;
        //cout << n << ' ' << m << '\n';
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j] = 0;
                cin >> mp[i][j];
            }
        }
        dfs(x0, y0, d0, k, n, m);
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans += vis[i][j];
                //cout << vis[i][j];
            }//cout << '\n';
        }
        printf("%d\n", ans);
    }
    return 0;
}