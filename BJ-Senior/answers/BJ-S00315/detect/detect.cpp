#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
struct node
{
    int l, r;
} seg[N];
int n, m, L, V, p[N * 10], d[N], v[N], a[N], cnt = 0, pre[N * 10], q[N];
bool cmp (node x, node y)
{
    if (x.r == y.r) return x.l > y.l;
    return x.r < y.r;
}
signed main ()
{
    freopen ("detect.in", "r", stdin);
    freopen ("detect.out", "w", stdout);
    int T; scanf ("%lld", &T);
    while (T--)
    {
        scanf ("%lld%lld%lld%lld", &n, &m, &L, &V);
        cnt = 0;
        for (int i = 1; i <= 1e6; i++) p[i] = 0;
        for (int i = 1; i <= 1e6; i++) pre[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf ("%lld%lld%lld", &d[i], &v[i], &a[i]);
            if (a[i] > 0)
            {
                double k = 1.0 * (((V * V * 1.0 - v[i] * v[i] * 1.0) * 1.0) / (2.0 * a[i]) + d[i] * 1.0);
                int xd = k; xd ++;
                xd = max (xd, d[i]);
                if (L >= xd) seg[++cnt] = {xd, L};
            }
            if (a[i] == 0)
            {
                if (v[i] > V)
                {
                    seg[++cnt] = {d[i], L};
                }
            }
            if (a[i] < 0)
            {
                double k = 1.0 * (((V * V * 1.0 - v[i] * v[i] * 1.0) * 1.0) / (2.0 * a[i]) + d[i] * 1.0);
                int xd = k;
                if (xd * 1.0 == k) xd--;
                xd = min (xd, L);
                if (xd >= d[i]) seg[++cnt] = {d[i], xd};
            }
        }
        for (int i = 1; i <= m; i++)
        {
            scanf ("%lld", &q[i]);
            p[q[i]] = 1;
        }
        for (int i = 1; i <= 1e6; i++)
        {
            pre[i] = pre[i - 1] + p[i];
        }
        int ans = 0;
        for (int i = 1; i <= cnt; i++)
        {
            int R = seg[i].r, L = seg[i].l;
            if (pre[R] - pre[L - 1] > 0)
            {
                ans++;
            }
        }
        printf ("%lld ", ans);
        int lstpos = -1; ans = 0;
        sort (seg + 1, seg + cnt + 1, cmp);
        for (int i = 1; i <= cnt; i++)
        {
            int L = seg[i].l, R = seg[i].r;
            if (L > R) 
            {
                continue;
            }
            if (L <= lstpos && lstpos <= R) 
            {
                continue;
            }
            if (pre[R] - pre[L - 1] == 0) continue;
            ans ++;
            int l = L, r = R;
            int ok = 0;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (pre[r] - pre[mid - 1])
                {
                    ok = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            lstpos = ok;
        }
        printf ("%lld\n", m - ans);
    }
    return 0;
}