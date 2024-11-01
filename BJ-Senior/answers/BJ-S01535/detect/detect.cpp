#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int NR = 1e5 + 5;

int n, m, L, V;
int d[NR], v[NR], a[NR];
double b[NR];
double p[NR];
int ans1, ans2;

struct node
{
    int l, r;
};
node c[NR];

bool cmp(node a, node b)
{
    if (a.r == b.r)
        return a.l < b.l;
    return a.r < b.r;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    int T;
    cin >> T;
    while (T --)
    {
        ans1 = ans2 = 0;

        cin >> n >> m >> L >> V;
        for (int i = 1;i <= n;i ++)
        {
            cin >> d[i] >> v[i] >> a[i];
            if (a[i] != 0)
                b[i] = (double)(V * V - v[i] * v[i]) / 2 / a[i] + d[i];
            //cout << b[i] << ' ';
        }
        for (int i = 1;i <= m;i ++)
            cin >> p[i];

        sort(p + 1, p + m + 1);

        for (int i = 1;i <= n;i ++)
        {
            int tl, tr;
            if (a[i] > 0)
            {
                tl = upper_bound(p + 1, p + m + 1, b[i]) - p;
                c[i].l = tl;
                c[i].r = m;
            }
            else if (a[i] < 0 && v[i] > V)
            {
                tl = lower_bound(p + 1, p + m + 1, d[i]) - p;
                tr = lower_bound(p + 1, p + m + 1, b[i]) - p;
                c[i].l = tl;
                c[i].r = tr - 1;
            }
            else if (a[i] == 0 && v[i] > V)
            {
                tl = lower_bound(p + 1, p + m + 1, d[i]) - p;
                c[i].l = tl;
                c[i].r = m;
            }
            else
            {
                c[i].l = c[i].r = 0;
            }
        }

        for (int i = 1;i <= n;i ++)
        {
            if (c[i].r == 0)
                continue;
            if (c[i].l <= c[i].r)
                ans1 ++;
        }

        sort(c + 1, c + n + 1, cmp);

        int lst = 0;
        for (int i = 1;i <= n;i ++)
        {
            if (c[i].r == 0)
                continue;
            if (c[i].l > c[i].r)
                continue;
            if (lst < c[i].l)
            {
                ans2 ++;
                lst = c[i].r;
            }
        }

        cout << ans1 << ' ' << m - ans2 << '\n';
    }

    return 0;
}
