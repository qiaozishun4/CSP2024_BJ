#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;

int n, m, k, ia[MAXN], a[MAXN], c[MAXN], d[25][MAXN];
char str[MAXN];

inline int lg2(int x) { return 31 ^ __builtin_clz(x); }

int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &ia[i]);
    for (int i = 1; i <= m; ++i) scanf("%d", &c[i]);
    k = lg2(n);
    if (n != (1 << k)) ++k;
    for (int i = 1; i <= k; ++i) {
        scanf("%s", str);
        for (int j = 1; j <= (1 << (k - i)); ++j) d[i][j] = str[j - 1] - '0';
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        int x[4];
        scanf("%d%d%d%d", &x[0], &x[1], &x[2], &x[3]);
        for (int i = 1; i <= n; ++i) a[i] = ia[i] ^ x[i % 4];
        int ans = 0;
        for (int t = 1; t <= m; ++t) {
            int cn = c[t];
            vector<int> tmp;
            for (int i = 1; i <= cn; ++i) tmp.push_back(i);
            int k = lg2(cn);
            for (int i = 1; i <= k; ++i) {
                int cc = (1 << (k - i));
                vector<int> tmp2;
                for (int j = 1; j <= cc; ++j) {
                    int x = 2 * j - 2, y = 2 * j - 1, win = 0;
                    if (d[i][j]) win = a[max(tmp[x], tmp[y])] >= j ? max(tmp[x], tmp[y]) : tmp[x] + tmp[y] - max(tmp[x], tmp[y]);
                    else win = a[min(tmp[x], tmp[y])] >= j ? min(tmp[x], tmp[y]) : tmp[x] + tmp[y] - min(tmp[x], tmp[y]);
                    tmp2.push_back(win);
                }
                tmp = tmp2;
            }
            ans ^= (t * tmp[0]);
        }
        printf("%d\n", ans);
    }
    return 0;
}