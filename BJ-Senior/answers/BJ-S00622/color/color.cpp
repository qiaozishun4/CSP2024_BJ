#include <cstdio>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <vector>
#include <array>
#include <utility>

#define wzc(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

const int N = 2e5 + 5, V = 1e6 + 5;

int a[N];
i64 mx[V];

inline i64 score(int x, int y)
{
    return x == y ? x : 0;
}

int main()
{
    wzc("color");

    int q; scanf("%d", &q);
    while (q--)
    {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        a[0] = a[n + 1] = 0;
        memset(mx, -100, sizeof mx); mx[0] = 0; // dp[0] = 0
        i64 ans = 0;
        for (int i = 1; i <= n; i++)
        {
            i64 dpi = std::max(ans, mx[a[i + 1]] + a[i + 1]) - score(a[i], a[i + 1]);
            ans = std::max(ans, dpi);
            mx[a[i]] = std::max(mx[a[i]], dpi);
        }
        for (int i = 1; i <= n; i++)
            ans += score(a[i - 1], a[i]);
        printf("%lld\n", ans);
    }

    return 0;
}