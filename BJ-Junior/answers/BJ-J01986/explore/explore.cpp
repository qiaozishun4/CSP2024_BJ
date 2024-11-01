#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e3 + 5;
int n, m, k, x, y, d;
char s[N][N];
int cx[] = {0, 1, 0, -1};
int cy[] = {1, 0, -1, 0};
bool tong[N][N];

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &k);
        scanf("%d%d%d", &x, &y, &d);
        memset(tong, 0, sizeof(tong));
        --x; --y;
        tong[x][y] = true;
        int ans = 1;
        for (int i = 0; i < n; ++i) 
            scanf("%s", s[i]);
        int tx, ty;
        for (int i = 1; i <= k; ++i) {
            tx = cx[d] + x;
            ty = cy[d] + y;
            if (tx < 0 || tx >= n || ty < 0 || ty >= m || s[tx][ty] == 'x') {
                d = (d + 1) % 4;
            } else {
                if (!tong[tx][ty]) {
                    ++ans;
                    tong[tx][ty] = true;
                }
                x = tx; y = ty;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}