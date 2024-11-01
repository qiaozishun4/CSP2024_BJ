#include <iostream>
#include <algorithm>
using namespace std;

const int nr = 1e5 + 5;

struct node
{
    int l, r;
} q[nr];

int T;
int d[nr], v[nr], a[nr], p[nr];

bool cmp(node p, node q)
{
    if (p.r != q.r)
    {
        return p.r < q.r;
    }
    return p.l < q.l;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        int n, m, L, V;
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++)
        {
            cin >> d[i] >> v[i] >> a[i];
            d[i] = L - d[i];
        }
        for (int i = m; i >= 1; i--)
        {
            cin >> p[i];
            p[i] = L - p[i];
        }
        int cnt1 = 0;
        for (int i = 1; i <= n; i++)
        {
            q[i] = {1, 0};
            if (a[i] == 0)
            {
                if (v[i] > V)
                {
                    q[i] = {1, upper_bound(p + 1, p + m + 1, d[i]) - p - 1};
                }
            }
            else if (a[i] > 0)
            {
                if (v[i] * v[i] + 2 * a[i] * d[i] <= V * V)
                {
                    continue;
                }
                if (v[i] > V)
                {
                    q[i] = {1, upper_bound(p + 1, p + m + 1, d[i]) - p - 1};
                }
                else
                {
                    q[i] = {1, lower_bound(p + 1, p + m + 1, d[i] - (V * V - v[i] * v[i]) / (2 * a[i])) - p - 1};
                }
            }
            else
            {
                if (v[i] * v[i] + 2 * a[i] * d[i] > V * V)
                {
                    q[i] = {1, upper_bound(p + 1, p + m + 1, d[i]) - p - 1};
                }
                else if (v[i] > V)
                {
                    q[i] = {upper_bound(p + 1, p + m + 1, d[i] - (V * V - v[i] * v[i]) / (2 * a[i])) - p, upper_bound(p + 1, p + m + 1, d[i]) - p - 1};
                }
            }
            if (q[i].l <= q[i].r)
            {
                cnt1++;
            }
        }
        cout << cnt1 << " ";
        sort(q + 1, q + n + 1, cmp);
        int last = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (q[i].l > q[i].r)
            {
                continue;
            }
            if (q[i].l > last)
            {
                last = q[i].r;
                cnt2++;
            }
        }
        cout << m - cnt2 << "\n";
    }
    return 0;
}
