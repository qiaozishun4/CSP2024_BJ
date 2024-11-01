#include <cstdio>
#include <algorithm>

int T, n, a[101], ans;
bool choose[101];

void dfs(int step) {
    if (step == n + 1) {
        int res = 0;
        for (int i = 1, add; i <= n; ++i) {
            add = 0;
            for (int j = i - 1; j; --j)
                if (choose[i] == choose[j]) {
                    add = a[i] == a[j] ? a[i] : 0;
                    break;
                }
            res += add;
        }
        ans = std::max(ans, res);
        return ;
    }
    choose[step] = true;
    dfs(step + 1);
    choose[step] = false;
    dfs(step + 1);
}

signed main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    for (scanf("%d", &T); T--; ) {
        ans = 0xcfcfcfcf;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", a + i);
        dfs(1);
        printf("%d\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
