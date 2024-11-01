#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int NR = 1e3 + 10;
char c[NR][NR];
bool vis[NR][NR];
int z[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m, k, sx, sy, sk;

bool in(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(vis, false, sizeof(vis));
        scanf("%d%d%d%d%d%d", &n, &m, &k, &sx, &sy, &sk);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf(" %c", &c[i][j]);
        //for(int i = 1; i <= n; i++) {
   //         for(int j = 1; j <= m; j++)
        //        printf("%c", c[i][j]);
     //       puts("");
      //  }
        int ans = 1;
        vis[sx][sy] = true;
        while(k--) {
            int nx = sx + z[sk][0], ny = sy + z[sk][1];
            // printf("! %d %d %d %d %d\n", sx, sy, z[sk][0], z[sk][1], ans);
            if(!in(nx, ny) || c[nx][ny] == 'x') sk = (sk + 1) % 4;
            else {
//                    puts("@");
                sx = nx; sy = ny;
//                cout << vis[sx][sy] << endl;
                if(!vis[sx][sy]) {
                    ans++;
                    vis[sx][sy] = true;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
