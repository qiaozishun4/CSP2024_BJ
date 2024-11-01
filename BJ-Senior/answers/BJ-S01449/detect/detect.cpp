#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct car
{
    long long d, v, a;
}c[100005];
bool cmp(car x, car y)
{
    return x.d < y.d;
}
long long T, n, m, L, V, p[100005], id[1000005];

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld%lld%lld%lld", &n, &m, &L, &V);
        bool flaga = true, flagb = true, flagc = true;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld%lld%lld", &c[i].d, &c[i].v, &c[i].a);
            if (c[i].a < 0)
            {
                flaga = false;
                flagb = false;
            }
            else if (c[i].a == 0)
            {
                flagb = false;
                flagc = false;
            }
            else
            {
                flagc = false;
                flaga = false;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%lld", &p[i]);
        }
        sort(p + 1, p + m + 1);
        sort(c + 1, c + n + 1, cmp);
        if (flaga)
        {
            int cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                if (c[i].d > p[m])
                {
                    break;
                }
                if (c[i].v > V)
                {
                    cnt++;
                }
            }
            cout << cnt << " ";
            if (cnt == 0)
            {
                cout << m << "\n";
            }
            else
            {
                cout << m - 1 << "\n";
            }
        }
        else if (flagb)
        {

            int cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                if (c[i].d > p[m])
                {
                    break;
                }
                long long tt = c[i].v * c[i].v + 2 * c[i].a * (p[m] - c[i].d);
                if (tt > V * V)
                {
                    cnt++;
                }
            }
            cout << cnt << " ";
            if (cnt == 0)
            {
                cout << m << "\n";
            }
            else
            {
                cout << m - 1 << "\n";
            }
        }
        else if (flagc)
        {
            for (int i = 1; i <= m; i++)
            {
                for (int j = p[i - 1] + 1; j <= p[i]; j++)
                {
                    id[j] = i;
                }
            }
            for (int i = p[m]; i <= L; i++)
            {
                id[i] = m + 1;
            }
            int cnt1 = 0, cnt2 = 0, now = 0, lr = 1;
            for (int i = 1; i <= n; i++)
            {
                while (c[i].d > p[lr] && lr <= m)
                {
                    lr++;
                }
                if (lr > m)
                {
                    break;
                }
                long long tt = c[i].v * c[i].v + 2 * c[i].a * (p[lr] - c[i].d);
                if (tt > V * V)
                {
                    cnt1++;
                    long long ss = c[i].d + ceil(1.0 * (V * V - c[i].v * c[i].v) / (2 * c[i].a));
                    if (now < lr)
                    {
                        cnt2++;
                        int ttt = id[ss] - 1;
                        now = ttt;
                    }
                    else
                    {
                        int ttt = id[ss] - 1;
                        now = min(now, ttt);
                    }
                }
            }
            cout << cnt1 << " " << m - cnt2 << "\n";
        }
    }
    return 0;
}