#include<bits/stdc++.h>
using namespace std;
int T, n, m, k, x, y, d, ans, dx[5] = {0, 0, 1, 0, -1}, dy[5] = {0, 1, 0, -1, 0};
char s[2001][2001];
bool vis[1001][1001][4];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i){
        memset(vis, false, sizeof(vis));
        ans = 0;
        scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &d);
        for(int j = 1; j <= n; ++j)
            scanf(" %s", s[j] + 1);
        for(int j = 1; j <= k; ++j){
            bool flag = true;
            for(int k = 0; k <= 3; ++k)
                if(vis[x][y][k]){
                    flag = false;
                    break;
                }
            if(flag)
                ++ans;
            if(vis[x][y][d])
                break;
            vis[x][y][d] = true;
            if(s[x + dx[d + 1]][y + dy[d + 1]] == '.'){
                x += dx[d + 1];
                y += dy[d + 1];
            }
            else
                d = (d + 1) % 4;
        }
        bool flag = true;
        for(int k = 0; k <= 3; ++k)
            if(vis[x][y][k]){
                flag = false;
                break;
            }
        if(flag)
            ++ans;
        printf("%d", ans);
        if(i < T)
            printf("\n");
    }
    return 0;
}
