#include<bits/stdc++.h>
using namespace std;
#define double long double

const double eps = 1e-9;
const int nr = 1e5 + 10;
const int lr = 1e6 + 10;
int n, m, L, V, d[nr], v[nr], a[nr], p[nr], num[lr], nxt[lr], lst[lr], s[lr], ln;
struct Line
{
    int l, r;
    friend bool operator < (const Line &a, const Line &b)
    { return a.l != b.l ? a.l < b.l : a.r > b.r; }
} line[nr];

double speed(int i, int len)
{
    return sqrtl(1.0 * v[i] * v[i] + 2.0 * a[i] * len);
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        ln = 0;
        memset(num, 0, sizeof(num));
        memset(lst, -0x3f, sizeof(lst));
        memset(nxt, 0x3f, sizeof(nxt));
        cin >> n >> m >> L >> V, L++;
        for (int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i], d[i]++;
        for (int i = 1; i <= m; i++) cin >> p[i], p[i]++, num[p[i]]++;
        int dn = 0;
        for (int i = 1; i <= L; i++) for (int j = 1; j <= num[i]; j++) p[++dn] = i;
        for (int i = 1; i <= L; i++) s[i] = s[i - 1] + num[i];
        for (int i = 1; i < p[1]; i++) nxt[i] = 1;
        for (int i = 1; i < m; i++)
            for (int j = p[i] + 1; j < p[i + 1]; j++)
                lst[j] = i, nxt[j] = i + 1;
        for (int i = p[m] + 1; i <= L; i++) lst[i] = m;
        for (int i = 1; i <= m; i++) lst[p[i]] = nxt[p[i]] = i;
        int res1 = 0;
        for (int i = 1; i <= n; i++)
        {
            int l, r;
            if (v[i] <= V && a[i] <= 0) continue;
            else if (v[i] >= V && a[i] >= 0) l = d[i], r = L;
            else
            {
                double t = 1.0 * (V - v[i]) / a[i];
                double s = 1.0 * v[i] * (V - v[i]) / a[i] + 0.5 * (V - v[i]) * (V - v[i]) / a[i];
                if (a[i] > 0) l = d[i] + (int)(s + 1), r = L;
                else if (a[i] == 0) l = d[i], r = L;
                else l = d[i], r = d[i] + ceil(s - 1);
                if (abs(d[i] + s - r) <= eps) r--;
                if (r > L) r = L;
            }
            if (v[i] == V) l++;
            if (l > r) continue;
            if (s[r] - s[l - 1] > 0) res1++;
            if (nxt[l] <= lst[r]) line[++ln] = {nxt[l], lst[r]};
        }
        sort(line + 1, line + ln + 1);
        int res2 = 0, r = 0;
        for (int i = 1; i <= ln; i++)
            if (line[i].l != line[i - 1].l && line[i].l > r) r = line[i].r, res2++;
            else r = min(r, line[i].r);
        cout << res1 << " " << m - res2 << '\n';
    }
    return 0;
}
