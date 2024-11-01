#include <bits/stdc++.h>
#define int long long
using namespace std;
int _;
struct car
{
    int d, v, a;
} c[100005];
struct seg
{
    int l, r;
} ;
vector <seg> sg;
inline bool cmp(seg x, seg y)
{
    if (x.r == y.r)
        return x.l < y.l;
    return x.r < y.r;
}
int p[100005];
#define getchar getchar_unlocked
inline int read()
{
    int x = 0;
    bool fl = 0;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            fl = 1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return fl ? -x : x;
}
signed main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    _ = read();
    while (_--)
    {
        sg.clear();
        int n = read(), m = read(), l = read(), v = read();
        for (int i = 1; i <= n; i++)
        {
            c[i].d = read(), c[i].v = read(), c[i].a = read();

        }
        for (int i = 1; i <= m; i++)
        {
            p[i] = read();
        }
        sort(p + 1, p + m + 1);
        int ans1 = 0;
        for (int i = 1; i <= n; i++)
        {
            // if (c[i].a == 0)
            // {
            //     if (c[i].v <= v)
            //         continue;
            //     int l = lower_bound(p + 1, p + m + 1, c[i].d) - p;
            //     if (l != m + 1)
            //     {
            //         sg.push_back((seg){l, m});
            //     }
            //     continue;
            // }
            int l = lower_bound(p + 1, p + m + 1, c[i].d) - p, r = m + 1;
            if (c[i].a >= 0)
            {
                while (l < r)
                {
                    int mid = (l + r >> 1);
                    if (sqrt(c[i].v * c[i].v + (p[mid] - c[i].d) * 2 * c[i].a) <= v)
                    {
                        l = mid + 1;
                    }
                    else
                        r = mid;
                }
            }
            else
            {
                if (sqrt(c[i].v * c[i].v + (p[l] - c[i].d) * 2 * c[i].a) > v)
                {
                    // printf("%.3lf\n", c[i].d + 1.0 * (v * v - c[i].v * c[i].v) / (2 * c[i].a));
                    r = lower_bound(p + 1, p + m + 1, c[i].d + 1.0 * (v * v - c[i].v * c[i].v) / (2 * c[i].a)) - p - 1;
                }
                else
                    l = m + 1;
                // r--;
            }
            if (l != m + 1)
            {
                ans1++;
                if (c[i].a < 0)
                {
                    sg.push_back((seg){l, r});
                }
                else
                {
                    sg.push_back((seg){l, m});
                }
            // printf("[%lld, %lld] id=%lld v=%lld a=%lld\n", sg[sg.size() - 1].l, sg[sg.size() - 1].r, i, c[i].v, c[i].a);
            }
        }
        printf("%ld ", sg.size());
        if (sg.size() == 0)
        {
            printf("%lld\n", m);
        }
        else
        {
            sort(sg.begin(), sg.end(), cmp);
            int fl = sg[0].r, cnt = 1;
            for (auto i : sg)
            {
                // printf("[%lld, %lld]\n", i.l, i.r);
                if (i.l <= fl && fl <= i.r)
                {
                    
                }
                else
                {
                    fl = i.r, cnt++;
                }
            }
            printf("%lld\n", m - cnt);
        }
    }
    return 0;
}