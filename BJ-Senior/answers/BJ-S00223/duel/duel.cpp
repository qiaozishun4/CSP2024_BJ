#include <cstdio>
#include <algorithm>

const int N = 1e5 + 2;
int n, a[N], ans, l = 1, r = 1;

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n); ans = n;
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    std::sort(a + 1, a + n + 1);
    a[n + 1] = 0x3f3f3f3f;
    while (l <= r and r <= n) {
        while (a[r] <= a[l])
            ++r;
        if (r > n)
            break;
        ++l; ++r;
        --ans;
    }
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
