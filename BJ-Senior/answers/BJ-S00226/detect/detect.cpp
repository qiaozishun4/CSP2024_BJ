#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int NR = 1e5 + 10;
ll a[NR], d[NR], v[NR], p[NR];
int n,m;

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        memset(d, 0, sizeof(d));
        memset(v, 0, sizeof(v));
        memset(a, 0, sizeof(a));
        memset(p, 0, sizeof(p));

        ll L, V;
        cin >>n >> m >> L >>V;
        for (int i = 1; i <= n; i++)
        {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int i = 1; i <= m; i++)
            cin >> p[i];
        sort(p+1, p+m+1);

        vector<pair<int, int>> de;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0)
            {
                if (v[i] > V)
                {
                    int start = lower_bound(p+1, p+m+1, d[i]) - p;
                    if (start <= m)
                    {
                        ans++;
                        de.push_back(make_pair(start, m));
                    }
                }
            } else if (a[i] > 0)
            {
                ll l = 0;

                if (V > v[i])
                {
                    l = (1LL * V * V - 1LL * v[i] * v[i]) / (2 * a[i]);
                } else if (v[i] > V)
                {
                    l = -1;
                }
                int start = lower_bound(p+1, p+m+1, d[i] + l + 1) - p;
                if (start <= m)
                {
                    ans++;
                    de.push_back(make_pair(start, m));
                }
            } else
            {
                ll l = 0;
                if (v[i] > V)
                {
                    l = (v[i] * v[i] - V * V - 1) / (2 * (-a[i]));
                    int start = lower_bound(p+1, p+m+1, d[i]) - p;
                    int ed = lower_bound(p+1, p+m+1, d[i]+l + 1) - p;
                    if (ed > start)
                    {
                        ans++;
                        de.push_back(make_pair(start, ed-1));
                    }
                }
            }
        }
        int lft = 0;
        if (de.size() >0)
        {
            sort(de.begin(), de.end(), [&](pair<int,int> A, pair<int,int> B) -> bool{
                    return A.second < B.second;
                 });
            int cur = de[0].second;
            lft = 1;
            for (int i = 1; i < de.size(); i++)
            {
                if (de[i].first <= cur) continue;
                else {
                    lft++;
                    cur = de[i].second;
                }
            }
        }
        cout << ans <<' ' << m - lft << endl;
    }

    return 0;
}
