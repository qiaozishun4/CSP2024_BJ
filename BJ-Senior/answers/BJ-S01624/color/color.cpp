#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;
int n, a[N], col[N], ans, lef[N], c[N];

int getAns() {
    int l1 = -1, l0 = -1;
    for (int i = 1; i <= n; ++i) {
        if (col[i] == 1) {
            lef[i] = l1;
            l1 = i;
        } else {
            lef[i] = l0;
            l0 = i;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (lef[i] == -1) c[i] = 0;
        else if (a[lef[i]] == a[i]) c[i] = a[i];
        else c[i] = 0;
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) res += c[i];
    return res;
}

void dfs(int x) {
    if (x == n + 1) {
        ans = max(ans, getAns());
        return;
    }
    col[x] = 1;
    dfs(x + 1);
    col[x] = 0;
    dfs(x + 1);
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        ans = -INF;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
        }
        dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}