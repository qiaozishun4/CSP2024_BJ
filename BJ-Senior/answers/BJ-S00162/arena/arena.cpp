#include <bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0;
    char c = getchar();
    bool f = 0;
    while (c < '0' || c > '9') f |= (c == '-'), c = getchar();
    while ('0' <= c && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    if (f) x = -x;
}
template <typename T> inline void write(const T &x) {
    if (x < 0) return write(-x);
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
const int N = 1e5 + 5;
int T, n, m, K, x[5], pa[N], a[N], c[N], d[18][N];
int tmp[18][N];
signed main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    read(n), read(m);
    for (int i = 1; i <= n; i++)
        read(pa[i]);
    for (int i = 1; i <= m; i++)
        read(c[i]);
    K = ceil(log2(n));
    for (int i = 1; i <= K; i++)
        for (int j = 1; j <= (1 << K - i); j++) {
            char c = getchar();
            while (c != 48 && c != 49) c = getchar();
            d[i][j] = c ^ 48;
        }
    read(T);
    while (T--) {
        read(x[0]), read(x[1]), read(x[2]), read(x[3]);
        for (int i = 1; i <= n; i++)
            a[i] = pa[i] ^ x[i & 3];
        int res = 0;
        for (int id = 1; id <= m; id++) {
            int k = log2(c[id]);
            for (int i = 0; i < (1 << k); i++)
                tmp[0][i] = i + 1;
            for (int r = 1; r <= k; r++) {
                for (int i = 0; i < (1 << k - r); i++) {
                    int person = i << 1 | d[r][i + 1];
                    if (a[tmp[r - 1][person]] >= r) tmp[r][i] = tmp[r - 1][person];
                    else tmp[r][i] = tmp[r - 1][person ^ 1];
                }
            }
            res ^= id * tmp[k][0];
        }
        write(res), putchar('\n');
    }
    return 0;
}
