#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define ld long double

struct Node
{
    int l, r;
};

const int NR = 1e5 + 10;
const int TR = 3005;
const ld eps = 1e-6;
ld d[NR], v[NR], a[NR], p[NR];
Node w[NR];

bool cmp(Node x, Node y)
{
    if (x.r != y.r) return x.r < y.r;
    return x.l < y.l;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        ld L, V;
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i];
        for (int i = 1; i <= m; i++) cin >> p[i];
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            int u = lower_bound(p + 1, p + m + 1, d[i]) - p;
            if (u > m) continue;
            if (a[i] == 0)
            {
                if (v[i] > V)
                {
                    w[++cnt].l = u;
                    w[cnt].r = m;
                }
            }
            if (a[i] > 0)
            {
                ld cur = (V * V - v[i] * v[i]) / (2 * a[i]) + d[i];
                int t = upper_bound(p + 1, p + m + 1, cur + eps) - p;
                if (cur + eps < p[m])
                {
                    w[++cnt].l = max(t, u);
                    w[cnt].r = m;
                }
            }
            if (a[i] < 0)
            {
                ld cur = (V * V - v[i] * v[i]) / (2 * a[i]) + d[i];
                int t = lower_bound(p + 1, p + m + 1, cur - eps) - p - 1;
                if (t >= u)
                {
                    w[++cnt].l = u;
                    w[cnt].r = t;
                }
            }
        }
        cout << cnt << " ";
        sort(w + 1, w + cnt + 1, cmp);
        int ans2 = 0, lst = -1;
        for (int i = 1; i <= cnt; i++)
        {
            if (lst < w[i].l)
            {
                lst = w[i].r;
                ans2++;
            }
        }
        cout << m - ans2 << '\n';
    }
    return 0;
}
