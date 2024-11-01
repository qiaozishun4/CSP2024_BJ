#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e4 + 7;
int t, n, m, k, x, y, d, nx, ny;
long long cnt;
char c[N][N];
bool vis[N][N];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    scanf("%d", &t);
    while(t--){
        memset(vis, false, sizeof vis);
        scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &d);
        for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) cin >> c[i][j];
        getchar();
        vis[x][y] = true;
        cnt = 1;
        for(int i = 1;i <= k;i++){
            if(d == 0) nx = x, ny = y + 1;
            else if(d == 1) nx = x + 1, ny = y;
            else if(d == 2) nx = x, ny = y - 1;
            else nx = x - 1, ny = y;
            if(nx < 1 || nx > n || ny < 1 || ny > m || c[nx][ny] == 'x') d = (d + 1) % 4;
            else x = nx, y = ny;
            if(vis[x][y] == false) cnt++, vis[x][y] = true;
        }
        printf("%lld\n", cnt);
    }
    return 0;
}