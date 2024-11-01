#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <array>
#include <utility>

#define wzc(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

const int N = 1e5 + 10;

int a[N];

int main()
{
    wzc("duel");

    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    std::sort(a, a + n);

    int i = 0, ans = 0;
    while (i < n)
    {
        int j = i;
        while (j < n && a[j] == a[i]) j++;
        ans = std::max(ans, j - i);
        i = j;
    }
    printf("%d\n", ans);

    return 0;
}