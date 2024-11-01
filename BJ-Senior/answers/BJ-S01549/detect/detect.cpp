#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int T, n, m;
ll D, V;
ll d[N], d2[N], v0[N], a[N];
int p[N];
struct info
{
    int l, r;
    bool operator < (const info &B) const
    {
        return l < B.l;
    }
} qj[N];

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    //15:20
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%lld%lld", &n, &m, &D, &V);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld%lld%lld", &d[i], &v0[i], &a[i]);
            if (a[i] >= 0) d2[i] = D;
            else d2[i] = min((ll)D, d[i] + 1ll * v0[i] * v0[i] / 2 / a[i]);
        }
        for (int i = 1; i <= m; i++)
            scanf("%d", &p[i]);
        sort(p + 1, p + 1 + m);
        int ans = 0, ans2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] <= 0)
            {
                if (v0[i] < V)
                {
                    qj[i].l = 1;
                    qj[i].r = 0;
                }
                else
                {
                    qj[i].l = lower_bound(p + 1, p + 1 + m, d[i]) - p;
                    int L = 0, R = m;
                    while (L != R)
                    {
                        int mid = (L + R + 1) >> 1, t = p[mid] - d[i];
                        if (V * V < v0[i] * v0[i] + 2 * a[i] * t) L = mid;
                        else R = mid - 1;
                    }
                    qj[i].r = L;
                }
            }
            else
            {
                qj[i].r = m;
                int L = 0, R = m + 1;
                while (L != R)
                {
                    int mid = (L + R) >> 1, t = p[mid] - d[i];
                    if (V * V < v0[i] * v0[i] + 2 * a[i] * t) R = mid;
                    else L = mid + 1;
                }
                qj[i].l = max((long)R, lower_bound(p + 1, p + 1 + m, d[i]) - p);
            }
            //printf("%d %d\n", qj[i].l, qj[i].r);
        }
        sort(qj + 1, qj + 1 + n);
        int mr = m + 1;
        for (int i = 1; i <= n; i++)
        {
            int tl = qj[i].l, tr = qj[i].r;
            if (tl > tr) continue;
            ans2++;
            if (tl > mr)
            {
                mr = m + 1;
                ans++;
            }
            mr = min(mr, tr);
        }
        if (mr != m + 1) ans++;
        printf("%d %d\n", ans2, m - ans);
    }
    return 0;
}
