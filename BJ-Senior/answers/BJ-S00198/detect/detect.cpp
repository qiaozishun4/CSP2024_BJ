#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int NR = 100010;
int d[NR], v[NR], a[NR], id[NR], p[NR];
struct Node
{
    int l, r;
} aft[NR], t[NR];
bool cmp(Node x, Node y)
{
    if (x.r == y.r) return x.l < y.l;
    return x.r < y.r;
}
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while (T--)
    {
        int n, m, L, V; cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++)
            cin >> d[i] >> v[i] >> a[i];
        for (int j = 1; j <= m; j++)
            cin >> p[j];
        sort(p + 1, p + m + 1);
        for (int i = 1; i <= n; i++)
        {
            int pos = lower_bound(p + 1, p + m + 1, d[i]) - p;
            if (pos == m + 1) id[i] = 1e9;
            else id[i] = pos;
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0)
            {
                if (v[i] > V) aft[i].l = id[i], aft[i].r = m;
                else aft[i].l = 1e9, aft[i].r = 1e9;
            }
            if (a[i] > 0)
            {
                if (v[i] > V) aft[i].l = id[i], aft[i].r = m;
                else
                {
                    int pos = 0;
                    double s1 = 1.0 * (V * V - v[i] * v[i]) / (2 * a[i]) + 1.0 * d[i];
                    pos = upper_bound(p + 1, p + m + 1, s1) - p;
                    if (pos == m + 1) aft[i].l = aft[i].r = 1e9;
                    else aft[i].l = pos, aft[i].r = m;
                }
            }
            if (a[i] < 0)
            {
                if (v[i] < V) aft[i].l = 1e9, aft[i].r = 1e9;
                else
                {
                    int pos = 0;
                    double s1 = 1.0 * (V * V - v[i] * v[i]) / (2 * a[i]) + 1.0 * d[i];
                    pos = lower_bound(p + 1, p + m + 1, s1) - p;
                    if (d[i] > p[pos - 1] && s1 <= p[pos]) aft[i].l = aft[i].r = 1e9;
                    else aft[i].l = id[i], aft[i].r = pos - 1;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            // cout << aft[i].l << " " << aft[i].r << '\n';
            if (id[i] == 1e9) continue;
            if (aft[i].l == 1e9 || aft[i].r == 1e9) continue;
            ans++;
            t[ans].l = aft[i].l, t[ans].r = aft[i].r;
        }
        cout << ans << ' ';
        int num = ans;
        sort(t + 1, t + num + 1, cmp);
        int last = 0; ans = 0;
        for (int i = 1; i <= num; i++)
        {
            // cout << last << " " << ans << '\n';
            if (last <= t[i].r && last >= t[i].l) ;
            else ans++, last = t[i].r;
        }
        cout << m - ans << '\n';
    }
    return 0;
}
