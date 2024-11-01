#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long T, n, m, L, V, d[N], v[N], a[N], p[N];
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        bool ta = 1, tb = 1;
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++)
        {
            cin >> d[i] >> v[i] >> a[i];
            if (a[i] != 0) ta = 0;
            if (a[i] <= 0) tb = 0;
        }
        long long pmin = 1e6 + 5, pmax = -1;
        for (int i = 1; i <= m; i++)
        {
            cin >> p[i];
            pmin = min(pmin, p[i]);
            pmax = max(pmax, p[i]);
        }
        if (ta)
        {
            int cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                if (d[i] > pmax) continue;
                if (v[i] > V) cnt++;
            }
            cout << cnt << " ";
            if (cnt == 0)
            {
                cout << m << endl;
            }
            else
            {
                cout << m - 1 << endl;
            }
            continue;
        }
        if (tb)
        {
            int cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                if (d[i] > pmax) continue;
                long long vs = (v[i] * v[i]) - 2 * a[i] * d[i] + 2 * a[i] * pmax;
                if (vs > V * V) cnt++;
            }
            cout << cnt << " ";
            if (cnt == 0)
            {
                cout << m << endl;
            }
            else
            {
                cout << m - 1 << endl;
            }
            continue;
        }
    }

    return 0;
}
