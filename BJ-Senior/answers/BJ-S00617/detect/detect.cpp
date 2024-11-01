#include <bits/stdc++.h>

using namespace std;

int n, m, L, V;
int p[150001];
struct Car
{
    int d, v, a; // v, a, V are 1e3, not need to use ll
    bool iso; // is Overspeed?
    int l, r; // the interval of sensors that will judge this car as overspeed
}c[150001];
vector <int> lis[150001];

bool CarOS(Car a, int x)
{
    if (p[x] < a.d) return false;
    if (a.a < 0)
    {
        if (a.v * a.v < 2 * (-a.a) * (p[x] - a.d)) return false;
    }
    if (a.v * a.v + 2 * a.a * (p[x] - a.d) > V * V) return true; // remember checking too large negative speeds cases
    return false;
}

void Solve()
{
    cin >> n >> m >> L >> V;
    for (int i = 1; i <= n; i++) 
    {
        cin >> c[i].d >> c[i].v >> c[i].a;
        c[i].iso = false;
        c[i].l = c[i].r = 0;
    }
    for (int i = 1; i <= m; i++) cin >> p[i], lis[i].clear();
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p[m] < c[i].d) continue;
        int fs = lower_bound(p + 1, p + m + 1, c[i].d) - p;
        int l = fs, r = m;
        if (c[i].a > 0)
        {
            int res = 0;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (CarOS(c[i], mid)) 
                {
                    c[i].iso = true;
                    res = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            if (c[i].iso)
            {
                c[i].l = res;
                c[i].r = m;
            }
        }
        else if (c[i].a < 0)
        {
            if (c[i].v <= V) continue;
            int res = 0;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (CarOS(c[i], mid))
                {
                    c[i].iso = true;
                    res = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            if (c[i].iso) 
            {
                c[i].l = fs;
                c[i].r = res;
            }
        }
        else
        {
            if (c[i].v > V) 
            {
                c[i].iso = true;
                c[i].l = fs;
                c[i].r = m;
            }
        }
        if (c[i].iso) 
        {
            ans1++;
            lis[c[i].r].push_back(c[i].l);
        }
    }
//   for (int i = 1; i <= n; i++) cerr << c[i].iso << ' ' << c[i].l << ' ' << c[i].r << endl;
//   cerr << endl;
    int las = 0;
    for (int i = 1; i <= m; i++)
    {
        if (lis[i].size() == 0) continue;
        bool need = false;
        for (auto it : lis[i])
        {
            if (it > las)
            {
                need = true;
                las = i;
                break;
            }
        }
        if (need) ans2++;
    }
    cout << ans1 << ' ' << m - ans2 << endl;
    return; 
}

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int _;
    cin >> _;
    while (_--) Solve();
    return 0;
}