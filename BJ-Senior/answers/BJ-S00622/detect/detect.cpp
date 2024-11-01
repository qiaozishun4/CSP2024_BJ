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
int n, m, L, V;
int d[N], v[N], a[N];
int p[N];
std::pair<int, int> I[N];

inline int log2(int x) { return 31 - __builtin_clz(x); }

bool overspeed(i64 d, i64 v, i64 a, i64 pos)
{
    return pos >= d && (pos - d) * 2 * a > (V * V - v * v);
}

int main()
{
    wzc("detect");

    int q; scanf("%d", &q);
    while (q--)
    {
        scanf("%d %d %d %d", &n, &m, &L, &V);
        for (int i = 0; i < n; i++) scanf("%d %d %d", &d[i], &v[i], &a[i]);
        for (int i = 0; i < m; i++) scanf("%d", &p[i]);
        std::sort(p, p + m);

        for (int i = 0; i < n; i++)
        {
            if (a[i] >= 0)
            {
                int r = m, l = r;
                for (int k = log2(m); k >= 0; k--)
                    if (overspeed(d[i], v[i], a[i], p[l - (1 << k)]))
                        l -= (1 << k);
                I[i] = {l, r};
            }
            else
            {
                int l = std::lower_bound(p, p + m, d[i]) - p, r = m;
                for (int k = log2(m - l); k >= 0; k--)
                    if (r - (1 << k) >= l && !overspeed(d[i], v[i], a[i], p[r - (1 << k)]))
                        r -= (1 << k);
                I[i] = {l, r};
            }
            // printf("i = %d, l = %d, r = %d\n", i, I[i].first, I[i].second);
        }

        int ans1 = 0;
        for (int i = 0; i < n; i++) if (I[i].second > I[i].first) ans1++;
        printf("%d ", ans1);

        int ans2 = 0, cur = -100;
        std::sort(I, I + n, [&](std::pair<int, int> x, std::pair<int, int> y) -> bool
        {
            return x.second < y.second;
        });
        // for (int i = 0; i < n; i++) printf("i = %d, l = %d, r = %d\n", i, I[i].first, I[i].second);
        for (int i = 0; i < n; i++)
        {
            if (I[i].first == I[i].second) continue;
            if (I[i].first <= cur) continue;
            cur = I[i].second - 1; ans2++;
            // printf("ans2++ on i = %d\n", i);
        }
        printf("%d\n", m - ans2);
    }
    return 0;
}