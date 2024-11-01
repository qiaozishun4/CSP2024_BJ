#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

struct Line
{
    int l, r;
};

Line l[100010], none = {0, 0};

bool cmp(Line x, Line y)
{
    return x.r < y.r;
}

const double EXP = 1e-5;
int T, n, m, L, V;
int p[100010], d[100010], v[100010], a[100010];

int fnd(int x, int add)
{
    int l = 1, r = m, ret = 1e9;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if ((p[mid]-add) * (p[mid]-add) < x) l = mid + 1;
        else r = mid - 1, ret = mid;
    }
    return ret;
}

void fnd2(int x, int add)
{
    int l = 1, r = m, ret = 1e9;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if ((p[mid]-add) * (p[mid]-add) <= x) l = mid + 1, ret = mid;
        else r = mid - 1;
    }
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        memset(p, 0, sizeof(p));
        memset(d, 0, sizeof(d));
        memset(v, 0, sizeof(v));
        memset(a, 0, sizeof(a));
        for (int i = 0; i <= 100009; i++)
        {
            l[i] = none;
        }
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &d[i], &v[i], &a[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &p[i]);
        }
        int cur = 0, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] <= V && a[i] <= 0) continue;
            if (v[i] > V && a[i] >= 0)
            {
                int lt = lower_bound(p + 1, p + m + 1, d[i]) - p;
                if (p[lt] >= d[i] && lt <= m) l[++cur] = Line{lt, m},ans++;

            }
            if (v[i] > V && a[i] < 0)
            {
                int lt = lower_bound(p + 1, p + m + 1, d[i]) - p;
                double x = 1.0 * (V * V - v[i] * v[i]) / (2 * a[i]) + d[i];
                int r = lower_bound(p + 1, p + m + 1, x) - p;
                if (p[r] > x) r--;
                if (p[lt] >= d[i] && lt <= r && p[r] <= x) l[++cur] = Line{lt, r},ans++;
            }
            if (v[i] <= V && a[i] > 0)
            {
                double x = 1.0 * (V * V - v[i] * v[i]) / (2 * a[i]) + d[i];
                int lt = lower_bound(p + 1, p + m + 1, x) - p;
                if (p[lt] >= x && lt <= m) l[++cur] = Line{lt, m},ans++;
            }
        }
        sort(l + 1, l + cur + 1, cmp);
        int now = 0, Ans = 0;
        for (int i = 1; i <= cur; i++)
        {
            if (l[i].l <= now) continue;
            now = l[i].r;
            Ans++;
        }
        cout << ans << " " << m - Ans << endl;
    }
    return 0;
}
