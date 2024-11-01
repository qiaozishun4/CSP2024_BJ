#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
#define int long long
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
int T, n, m, L, V, le, ri;
int p[N], f[N], last[N], qu[N * 2];
struct car
{
    int d, v, a;
}a[N];
bool cmp(car x, car y) {return x.d < y.d;}
int find(int x)
{
    int l = 1, r = m, mid, res = -1;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (2 * a[x].a * p[mid] >= 2 * a[x].a * a[x].d - a[x].v * a[x].v) l = mid + 1, res = mid;
        else r = mid - 1;
    }
    return res;
}
signed main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    T = read();
    while (T--)
    {
        n = read(), m = read(), L = read(), V = read();
        for (int i = 1; i <= n; i++) a[i].d = read(), a[i].v = read(), a[i].a = read();
        for (int i = 1; i <= m; i++) p[i] = read();
        for (int i = 0; i <= m; i++) f[i] = 0x3f3f3f3f, last[i] = 0, qu[i] = 0;
        sort(p + 1, p + m + 1);
        sort(a + 1, a + n + 1, cmp);
        int ans = n, cur = 1;
        for (int i = 1; i <= n; i++)
        {
            while (cur <= m && p[cur] < a[i].d) cur++;
            if (cur > m) {ans--; continue;}
            if (a[i].a == 0)
            {
                if ((a[i].v * a[i].v - 2 * a[i].a * a[i].d) <= V * V) ans--;
                else last[m] = max(last[m], cur);
            }
            if (a[i].a < 0)
            {
                int R = find(i);
                if (R < cur) {ans--; continue;}
                if ((a[i].v * a[i].v - 2 * a[i].a * a[i].d) <= V * V - 2 * p[cur] * a[i].a) ans--;
                else
                {
                    int l = cur, r = R, mid = (l + r) >> 1, res = R + 1;
                    while (l <= r)
                    {
                        mid = (l + r) >> 1;
                        if ((a[i].v * a[i].v - 2 * a[i].a * a[i].d) <= V * V - 2 * p[mid] * a[i].a) res = mid, r = mid - 1;
                        else l = mid + 1;
                    }
                    last[res - 1] = max(last[res - 1], cur);
                }
            }
            if (a[i].a > 0)
            {
                if ((a[i].v * a[i].v - 2 * a[i].a * a[i].d) <= V * V - 2 * p[m] * a[i].a) ans--;
                else
                {
                    int l = cur, r = m, mid = (l + r) >> 1, res = cur - 1;
                    while (l <= r)
                    {
                        mid = (l + r) >> 1;
                        if ((a[i].v * a[i].v - 2 * a[i].a * a[i].d) <= V * V - 2 * p[mid] * a[i].a) res = mid, l = mid + 1;
                        else r = mid - 1;
                    }
                    last[m] = max(last[m], res + 1);
                }
            }
        }
        printf("%lld ", ans);
        for (int i = 1; i <= m; i++) last[i] = max(last[i - 1], last[i]);
        le = 0, ri = 0;
        f[0] = 0;
        for (int i = 1; i <= m; i++)
        {
            while (le <= ri && qu[le] < last[i - 1]) le++;
            f[i] = min(f[i], f[qu[le]] + 1);
            while (le <= ri && f[i] <= f[qu[ri]]) ri--;
            qu[++ri] = i;
        }
        ans = 0x3f3f3f3f;
        for (int i = last[m]; i <= m; i++) ans = min(ans, f[i]);
        printf("%lld\n", m - ans);
    }
    return 0;
}