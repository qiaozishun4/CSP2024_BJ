#include <cstring>
#include <cstdio>
#include <random>
#include <cmath>

const int N = 1e5 + 1;
int T, n, m, a[N], ap[N], c[N], x[4], ans = 0;
bool d[20][N];
char s[N];

namespace Calc {
    int a[N], b[N];
    int calc(int p) {
        memcpy(a, ::a, sizeof a);
        for (int i = 1; i <= p; ++i)
            b[i] = i;
        for (int i = p, r = 1; i > 1; i >>= 1, ++r)
            for (int j = 1, z; j <= i >> 1; ++j) {
                if (d[r][j])
                    z = j << 1;
                else
                    z = (j << 1) - 1;
                if (a[z] >= r) {
                    a[j] = a[z];
                    b[j] = b[z];
                }
                else {
                    a[j] = (z & 1) ? a[j << 1] : a[(j << 1) - 1];
                    b[j] = (z & 1) ? b[j << 1] : b[(j << 1) - 1];
                }

            }
        return b[1];
    }
}
using Calc::calc;

signed main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", ap + i);
    for (int i = 1; i <= m; ++i)
        scanf("%d", c + i);
    for (int i = 1, nlog = std::log2(n + n - 1); i <= nlog; ++i) {
        scanf("%s", s);
        for (int j = 1, len = strlen(s); j <= len; ++j)
            d[i][j] = s[j - 1] - '0';
    }
    for (scanf("%d", &T); T--; ) {
        for (int i = 0; i < 4; ++i)
            scanf("%d", x + i);
        for (int i = 1; i <= n; ++i)
            a[i] = ap[i] xor x[i & 3];
        ans = 0;
        for (int i = 1; i <= m; ++i)
            ans xor_eq i * calc(c[i]);
        printf("%d\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
