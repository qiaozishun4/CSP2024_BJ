#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

struct Car
{
    int d, v, a;
}c[100005];
int s[100005];

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, l, vv;
        cin >> n >> m >> l >> vv;
        int p;
        for (int i = 1; i <= n; i++)
        {
            cin >> c[i].d >> c[i].v >> c[i].a;
            if (i == 1)
            {
                if (c[i].a > 0) p = 1;
                if (c[i].a == 0) p = 0;
                if (c[i].a < 0) p = -1;
            }
            else
            {
                if (c[i].a > 0 && p != 1) p = 100;
                if (c[i].a == 0 && p != 0) p = 100;
                if (c[i].a < 0 && p != -1) p = 100;
            }
        }
        for (int i = 1; i <= m; i++)
            cin >> s[i];
        sort(s + 1, s + m + 1);
        if (p == 0)
        {
            int cnt = 0;
            for (int i = 1; i <= n; i++)
                if (c[i].d <= s[m] && c[i].v > vv)
                    cnt++;
            if (cnt != 0) cout << cnt << " " << m - 1 << endl;
            else cout << 0 << " " << m << endl;
        }
        else if (p == 1)
        {
            int cnt = 0;
            for (int i = 1; i <= n; i++)
                if (c[i].d <= s[m] && sqrt(1ll * 1.0 * c[i].v * c[i].v + 2 * c[i].a * (s[m] - c[i].d)) > 1.0 * vv)
                    cnt++;
            if (cnt != 0) cout << cnt << " " << m - 1 << endl;
            else cout << 0 << " " << m << endl;
        }
    }
    return 0;
}