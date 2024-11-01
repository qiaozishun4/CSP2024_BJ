#include <bits/stdc++.h>
using namespace std;
long double v[100010], a[100010], d[100010], p[100010];
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        int L, V;
        cin >> n >> m >> L >> V;
        bool A = true, B = true, C = true;
        for (int i = 1; i <= n; ++i)
        {
            cin >> d[i] >> v[i] >> a[i];
            if (a[i] > 0) A = C = false;
            else if (a[i] < 0) A = B = false;
            else B = C = false;
        }
        for (int i = 1; i <= m; ++i) cin >> p[i];
        sort(p + 1, p + m + 1);
        if (A)
        {
            int out = 0;
            for (int i = 1; i <= n; ++i)
            {
                if (d[i] > p[m]) continue;
                if (v[i] > V)
                {
                    ++out;
                }
            }
            cout << out << ' ' << (out == 0 ? m : m - 1) << "\n";
        }
        else if (B)
        {
            int out = 0;
            for (int i = 1; i <= n; ++i)
            {
                double s;
                if (d[i] > p[m]) continue;
                s = p[m] - d[i];
                long double speed = sqrt(v[i] * v[i] + 2 * a[i] * s);
                if (speed > V) ++out;
            }
            cout << out << ' ' << (out == 0 ? m : m - 1) << "\n";
        }
    }

    return 0;
}
