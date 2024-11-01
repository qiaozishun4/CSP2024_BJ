#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
int T, n, m, L, V, d, v, a, l[100005], r[100005], p[100005], q, cnt, cnt2, minn;
struct Inter
{
    int l, r;
} inters[100005];
bool vis[100005];
bool cmp(Inter a, Inter b)
{
    if (a.l == b.l)
        return a.r > b.r;
    return a.l < b.l;
}
signed main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++)
        {
            cin >> d >> v >> a;
            if (a == 0)
            {
                if (v > V) l[i] = d, r[i] = L;
                else l[i] = r[i] = -1;
            }
            else if (a > 0)
            {
                if (v > V) l[i] = d, r[i] = L;
                else if ((V + v) * (V - v) >= (a + a) * (L - d))
                    l[i] = r[i] = -1;
                else l[i] = (V + v) * (V - v) / (a + a) + d + 1, r[i] = L;
            }
            else
            {
                if (v <= V) l[i] = r[i] = -1;
                else if ((V + v) * (V - v) < (a + a) * (L - d))
                    l[i] = d, r[i] = L;
                else l[i] = d, r[i] = ((V + v) * (V - v) + a + a + 1) / (a + a) + d - 1;
            }
        }
        cnt = 0;
        for (int i = 1; i <= m; i++)
            cin >> p[i];
        for (int i = 1; i <= n; i++)
        {
            int ll = lower_bound(p + 1, p + m + 1, l[i]) - p;
            int rr = upper_bound(p + 1, p + m + 1, r[i]) - p - 1;
            if (ll <= rr)
                inters[++cnt] = {ll, rr};
        }
        sort(inters + 1, inters + cnt + 1, cmp);
        memset(vis, 0, sizeof(vis));
        minn = inters[cnt].r;
        for (int i = cnt - 1; i >= 1; i--)
            if (inters[i].r < minn)
                minn = inters[i].r;
            else
                vis[i] = true;
        q = 1;
        cnt2 = 0;
        while (vis[q]) q++;
        while (q <= cnt)
        {
            for (int i = q; i <= n; i++)
            {
                if (!vis[i] && inters[i].l <= inters[q].r)
                    vis[i] = true;
                else if (!vis[i])
                    break;
            }
            while (vis[q]) q++;
            cnt2++;
        }
        cout << cnt << " " << m - cnt2 << endl;
    }
    return 0;
}
