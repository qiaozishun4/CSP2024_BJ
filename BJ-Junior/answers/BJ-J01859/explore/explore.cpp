#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long k,d,x,y,n,m,t;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        bool vis[1001][1001] = {};
        char c[1001][1001];
        vis[x][y] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin >> c[i][j];
        long long ans = 1;
        while(k--){
            long long nx = x + dx[d],ny = y + dy[d];
            if(nx > n || nx <= 0 || ny > m || ny <= 0 || c[nx][ny] == 'x'){
                d = (d + 1) % 4;
            }
            if(nx <= n && nx > 0 && ny <= m && ny > 0 && c[nx][ny] == '.'){
                x += dx[d],y += dy[d];
                if(!vis[x][y]){
                    ans++;
                    vis[x][y] = 1;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
