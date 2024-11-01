#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
typedef long long LL;
const LL N = 1010;
LL t, n, m, k, x, y, d;
LL dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, a[N][N], h[N][N], v[N][N][4];
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    scanf("%lld", &t);
    while (t--) {
        memset(h, 0, sizeof(h));
        memset(v, 0, sizeof(v));
        scanf("%lld%lld%lld", &n, &m, &k);
        scanf("%lld%lld%lld", &x, &y, &d);
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            for (int j = 1; j <= m; j++) {
                if (s[j - 1] == '.') a[i][j] = 0;
                else a[i][j] = 1;
            }
        }

        while (k--) {
            if (v[x][y][d]) break;
            h[x][y] = 1;
            v[x][y][d] = 1;
            LL nx = x + dx[d];
            LL ny = y + dy[d];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m && !a[nx][ny]) {
                x = nx;
                y = ny;
            } else {
                d = (d + 1) % 4;
            }
        }

        h[x][y] = 1;
        LL res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (h[i][j]) res++;
            }
        }

        printf("%lld\n", res);
    }
}