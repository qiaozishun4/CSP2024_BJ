#include<bits/stdc++.h>
using namespace std;
int n, m, k, mp[1005][1005], d, t, x, y, v[1005][1005];
int p[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    scanf("%d", &t);
    while(t--){
        int ans = 1;
        scanf("%d%d%d", &n, &m, &k);
        scanf("%d%d%d", &x, &y, &d);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                char c; scanf(" %c", &c);
                if(c == '.') mp[i][j] = 0;
                else if(c == 'x') mp[i][j] = 1;
            }
        memset(v, 0, sizeof(v));
        v[x][y] = 1;
        while(k--){
            int nx = x + p[d][0], ny = y + p[d][1];
            if(nx < 1 || ny < 1 || nx > n || ny > m || mp[nx][ny] == 1){
                d = (d + 1) % 4;
            }else{
                x = nx; y = ny; ans += 1 - v[x][y]; v[x][y] = 1;
            }
            //printf("%d %d %d\n", x, y, ans);
        }printf("%d\n", ans);
    }
    return 0;
}
