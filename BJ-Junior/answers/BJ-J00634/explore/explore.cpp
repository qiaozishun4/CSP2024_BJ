#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
bool maps[N][N];
bool vis[N][N];
int T;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m, k, cnt, x, y, d;
char ls;

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> T;
    while(T--) {
        cnt = 1;
        memset(maps, 0, sizeof(maps));
        memset(vis, 0, sizeof(vis));
        scanf("%d%d%d", &n, &m, &k);
        scanf("%d%d%d", &x, &y, &d);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                scanf(" %c", &ls);
                if(ls == '.') maps[i][j] = 1;
                else maps[i][j] = 0;
            }
        }
        vis[x][y] = 1;
        for(int i = 1; i <= k; i++) {
            int tx = dx[d]+x;
            int ty = dy[d]+y;
            if(tx < 1 || tx > n || ty < 1 || ty > m || !maps[tx][ty]) {
                d++;
                d %= 4;
            }
            else {
                if(!vis[tx][ty]) {
                    vis[tx][ty] = 1;
                    cnt++;
                }
                x = tx;
                y = ty;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}