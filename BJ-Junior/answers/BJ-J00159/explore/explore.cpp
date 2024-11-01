#include <bits/stdc++.h>
using namespace std;

int t;

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    scanf("%d", &t);
    while (t--){
        int n, m, k, x, y, d, cnt = 0;
        char a[1005][1005];
        bool vis[1005][1005];
        scanf("%d %d %d %d %d %d", &n, &m, &k, &x, &y, &d);
        vis[x][y] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf(" %c", &a[i][j]);
        //for (int i = 1; i <= n; i++){
        //    for (int j = 1; j <= m; j++)
        //        printf("%c ", a[i][j]);
        //    printf("\n");
        //}
        for (int i = 1; i <= k; i++){
            if (d == 0) y++;
            else if (d == 1) x++;
            else if (d == 2) y--;
            else x--;

            if (a[x][y] == 'x' || (x < 1 || x > n) || (y < 1 || y > m)) {
                if (d == 0) y--;
                else if (d == 1) x--;
                else if (d == 2) y++;
                else x++;
                d = (d + 1) % 4;
            }
            else {
                // if (!vis[x][y]) cnt ++;
                vis[x][y] = true;
            }



        }
        for (int i = 1; i <= n; i++)
                    for (int j = 1; j <= m; j++)
                        if (vis[i][j]) cnt ++;
        printf("%d", cnt);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}