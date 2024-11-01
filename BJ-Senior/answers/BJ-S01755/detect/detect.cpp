#include <bits/stdc++.h>
#define int long long
using namespace std;
int l[100010], r[100010], p[100010];
signed main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, L, V;
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++)
        {
            int d, v, a;
            cin >> d >> v >> a;
            if (a == 0)
            {
                if (v > V) l[i] = d, r[i] = L;
                else l[i] = r[i] = -1;
            }
            else if (a > 0)
            {
                if (v > V) l[i] = d, r[i] = L;
                else
                {
                    int x = d + (V * V - v * v) / (2 * a) + 1;
                    if (x > L) l[i] = r[i] = -1;
                    else l[i] = x, r[i] = L;
                }
            }
            else
            {
                if (v <= V) l[i] = r[i] = -1;
                else
                {
                    int x = d + (v * v - V * V - 2 * a - 1) / (-2 * a) - 1;
                    if (x > L) l[i] = d, r[i] = L;
                    else l[i] = d, r[i] = x;
                }
            }
        }
        for (int i = 1; i <= m; i++) cin >> p[i];
        int ans1 = 0, ans2 = 0;
        vector<pair<int, int>> vec;
        for (int i = 1; i <= n; i++)
        {
            if (l[i] == -1) continue;
            int x = lower_bound(p + 1, p + m + 1, l[i]) - p;
            if (x > m || p[x] > r[i]) continue;
            ans1++;
            vec.push_back({l[i], r[i]});
        }
        sort(vec.begin(), vec.end());
        multiset<pair<int, int>> s;
        for (int i = 0; i < vec.size(); i++) s.insert({vec[i].second, i});
        int now = 0;
        while (now < vec.size())
        {
            int x = (*s.begin()).second, y = upper_bound(p + 1, p + m + 1, vec[x].second) - p - 1;
            while (now < vec.size() && vec[now].first <= p[y]) s.erase(s.find({vec[now].second, now})), now++;
            ans2++;
        }
        cout << ans1 << " " << m - ans2 << '\n';
    }
    return 0;
}
/*
1
10 10 150307 247
62978 968 -5
51700 883 -3
40408 564 -1
60366 870 -41
35943 797 -7
47476 595 -11
59020 672 -10
81024 964 -11
80637 695 -5
66114 874 -1
46720 48066 57373 60882 68842 72773 82820 116695 122159 150307
*/