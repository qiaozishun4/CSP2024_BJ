#include<bits/stdc++.h>
using namespace std;
constexpr int N = 100005, M = 1000005;
int T, n, m, L, d[N], v[N], a[N], p[N], tot, ans;
pair<int, int> se[N];
double V, s[N];
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> L >> V;
        V += 1e-9;
        for(int i = 1; i <= n; ++i)
        {
            cin >> d[i] >> v[i] >> a[i];
            if(a[i] <= 0 && v[i] <= V)
                s[i] = -1;
            else if(a[i] == 0 && v[i] > V)
                s[i] = L;
            else if(a[i] > 0 && v[i] > V)
                s[i] = d[i];
            else
                s[i] = d[i] + (V * V - 1.0 * v[i] * v[i]) / 2.0 / a[i];
            if(a[i] > 0 && s[i] < d[i])
                s[i] = d[i];
        }
        for(int i = 1; i <= m; ++i)
            cin >> p[i];
        sort(p + 1, p + m + 1);
        tot = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(s[i] == -1)
                continue;
            if(a[i] <= 0)
            {
                int l = lower_bound(p + 1, p + m + 1, d[i]) - p, r = upper_bound(p + 1, p + m + 1, (int)floor(s[i] + 1e-10)) - 1 - p;
                if(l <= r)
                    se[++tot] = {r, l};
            }
            else
            {
                int l = lower_bound(p + 1, p + m + 1, (int)ceil(s[i] - 1e-10)) - p, r = m;
                if(l <= r)
                    se[++tot] = {r, l};
            }
        }
        if(tot == 0)
        {
            cout << "0 " << m << '\n';
            continue;
        }
        sort(se + 1, se + tot + 1);
        int minr = se[1].first;
        ans = 0;
        for(int i = 1; i <= tot; ++i)
        {
            if(minr < se[i].second)
            {
                ++ans;
                minr = se[i].first;
            }
        }
        cout << tot << ' ' << m - ans - 1 << '\n';
    }
    return 0;
}
