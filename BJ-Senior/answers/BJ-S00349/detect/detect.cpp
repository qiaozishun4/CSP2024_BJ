#include <bits/stdc++.h>
#define i64 long long
#define f64 double

const i64 MAXN = 2e5 + 64;

i64 n, m, L, V;

struct node
{
    i64 d, v, a;
} che[MAXN];

f64 calc(i64 p, i64 q)
{
    i64 v0 = che[q].v, a = che[q].a;
    i64 x = p - che[q].d;
    if (x < 0) return 0;
    f64 vv = 1.0d*v0*v0+2.0d*a*x;
    if (vv < 0) return 0;
    f64 v = std::sqrt(vv);
    return v;
}

i64 p[MAXN];

i64 eed(i64 q)
{
    i64 l = std::lower_bound(p + 1, p + 1 + m, che[q].d) - p, r = m;
    //return l;
    while (l < r)
    {
        i64 mid = ((l + r + 1) >> 1);
        if (calc(p[mid], q) > V)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    return l;
}

i64 pst(i64 q) {
    i64 l = std::lower_bound(p + 1, p + 1 + m, che[q].d) - p, r = m;
    while (l < r)
    {
        i64 mid = ((l + r) >> 1);
        if (calc(p[mid], q) <= V)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}

i64 ecc;

struct node1
{
    i64 st, ed;
} E[MAXN];
i64 tp;

bool cmp(const node1 &lhs, const node1 &rhs)
{
    return lhs.ed < rhs.ed;
}

i64 rped;

void solve()
{
    memset(p, 0, sizeof(p)), ecc = 0, tp = 0, rped = 0;
    assert(scanf("%lld%lld%lld%lld", &n, &m, &L, &V));
    for (i64 i = 1, d, v, a; i <= n; ++i) assert(scanf("%lld%lld%lld", &d, &v, &a)), che[i] = {d, v, a};
    for (i64 i = 1; i <= m; ++i) assert(scanf("%lld", &p[i]));
    std::sort(p + 1, p + 1 + m, std::less<i64>());
    for (i64 i = 1; i <= n; ++i)
    {
        i64 ps = std::lower_bound(p + 1, p + 1 + m, che[i].d) - p;
        if (che[i].a < 0)
        {
            f64 v = calc(p[ps], i);
            if (v > V)
            {
                ++ecc;
                E[++tp] = {ps, eed(i)};
                //printf("!!! p: %lld -> %lld\n", j, i);
            }
        }
        else
        {
            f64 v = calc(p[m], i);
            if (v > V)
            {
                ++ecc;//, sig = 1;
                rped = std::max(rped, pst(i));
                //E[++tp] = {ped(i), m};
                //printf("!!! p: %lld -> %lld\n", j, i);
            }
        }
    }
    printf("%lld ", ecc);
    std::sort(E + 1, E + 1 + tp, cmp);
    i64 fed = 0, c1 = 0;
    for (i64 i = 1; i <= tp; ++i)
    {
        if (E[i].st > fed)
        {
            fed = E[i].ed;
            ++c1;
        }
    }
    if (rped > fed) ++c1;
    printf("%lld\n", m - c1);
}

i64 T;

signed main()
{
    assert(freopen("detect.out", "w", stdout));
    assert(freopen("detect.in", "r", stdin));
    assert(scanf("%lld", &T));
    while (T--) solve();
    return 0;
}
