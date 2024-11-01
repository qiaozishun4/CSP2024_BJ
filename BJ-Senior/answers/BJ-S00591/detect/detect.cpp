#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define double long double

using namespace std;

const int N = 1e5 + 5;
const double eps = 1e-12;
int T, n, m, L, V, b[N], now, ans1, ans2;
struct car{
    int d, v, a, eds, bgs;
    double ed, bg;
}p[N];

inline bool cmp_eds(car u, car v){return u.eds < v.eds;}

inline int get_up(double x)
{
    if(b[m] < x)    return m+1;
    register int l = 1, r = m, res;
    while(l <= r)
    {
        register int mid = (l+r)>>1;
        if(b[mid] < x)
            l = mid + 1;
        else
            r = mid - 1, res = mid;
    }
    return res;
}

inline int get_lo(double x)
{
    if(b[1] > x)    return 0;
    register int l = 1, r = m, res;
    while(l <= r)
    {
        register int mid = (l+r)>>1;
        if(b[mid] > x)
            r = mid - 1;
        else
            l = mid + 1, res = mid;
    }
    return res;
}

void solve()
{
    scanf("%lld %lld %lld %lld", &n, &m, &L, &V);
    for(register int i = 1;i <= n;i++)
    {
        scanf("%lld %lld %lld", &p[i].d, &p[i].v, &p[i].a);
        if(p[i].a > 0)
        {
            p[i].ed = L;
            if(p[i].v > V)  p[i].bg = p[i].d;
            else
            {
                register double t = 1.0 * (V - p[i].v) / p[i].a;
                p[i].bg = p[i].d + 1.0 * (p[i].v + V) * t / 2 + eps;
                if(p[i].bg > L) p[i].bg = L+1;
            }
        }
        else if(p[i].a == 0)
        {
            if(p[i].v > V)  p[i].bg = p[i].d, p[i].ed = L;
            else    p[i].bg = p[i].ed = L+1;
        }
        else
        {
            if(p[i].v < V)  p[i].bg = p[i].ed = L+1;
            else
            {
                p[i].bg = p[i].d;
                register double t = 1.0 * (V - p[i].v) / p[i].a;
                p[i].ed = p[i].d + 1.0 * (p[i].v + V) * t / 2 - eps;
                if(p[i].ed > L) p[i].ed = L;
            }
        }
    }
    for(register int i = 1;i <= m;i++)
        scanf("%lld", &b[i]);
    sort(b + 1, b + m + 1);
    ans1 = now = ans2 = 0;
    for(register int i = 1;i <= n;i++)
    {
        p[i].bgs = get_up(p[i].bg);
        p[i].eds = get_lo(p[i].ed);
        //printf("%.6lf %.6lf %lld %lld\n", p[i].bg, p[i].ed, p[i].bgs, p[i].eds);
        if(p[i].bgs <= p[i].eds)
            ans1++;
    }
    sort(p + 1, p + n + 1, cmp_eds);
    for(register int i = 1;i <= n;i++)
    {
        if(p[i].bgs > p[i].eds || p[i].bgs > m || p[i].eds < 1) continue;
        if(now < p[i].bgs)
            ans2++, now = p[i].eds;
    }
    printf("%lld %lld\n", ans1, m - ans2);
    return ;
}

signed main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%lld", &T);
    while(T--)
        solve();
    return 0;
}
