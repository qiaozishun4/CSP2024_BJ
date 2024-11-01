#include <cstdio>

const int N = 2001;
int T, n, k, q, l[N], s[N][N], r, c, last;
bool flag;

int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    for (scanf("%d", &T); T--; ) {
        scanf("%d%d%d", &n, &k, &q);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", l + i);
            for (int j = 1; j <= l[i]; ++j)
                scanf("%d", &s[i][j]);
        }
        while (q--) {
            scanf("%d%d", &r, &c);
            flag = false;
            for (int i = 1; i <= n; ++i) {
                last = 0xcfcfcfcf;
                if (flag)
                    break;
                else
                    for (int j = 1; j <= l[i]; ++j) {
                        if (s[i][j] == c)
                            if (j - last + 1 <= k) {
                                flag = true;
                                break;
                            }
                        if (s[i][j] == 1)
                            last = j;
                    }
            }
            printf("%d\n", flag);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
