#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

struct car
{
    double d, v, a;
};

struct line
{
    int a, b;
};

car c[100005];
double posm[100005];
int ans = 0, num;
bool isFa[100005];
line l[100005];

bool cmp(int x, int y)
{
    return x < y;
}

bool cmp2(line x, line y)
{
    return x.b < y.b;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        ans = 0;
        num = 0;
        memset(c, 0, sizeof(c));
        memset(posm, 0, sizeof(posm));
        memset(isFa, false, sizeof(isFa));
        int n, m;
        double V, L;
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++)
        {
            cin >> c[i].d >> c[i].v >> c[i].a;
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> posm[i];
        }
        sort(posm + 1, posm + m + 1, cmp);
        for (int i = 1; i <= n; i++)
        {
            if (c[i].a >= 0)
            {
                if (sqrt(c[i].v * c[i].v + 2 * c[i].a * (L - c[i].d)) > V)
                {
                    ans++;
                    isFa[i] = true;
                }
            }
            else
            {
                int temp = upper_bound(posm + 1, posm + m + 1, c[i].d) - posm;
                if (sqrt(c[i].v * c[i].v + 2 * c[i].a * (posm[temp] - c[i].d)) > V)
                {
                    ans++;
                    isFa[i] = true;
                }
            }
        }
        cout << ans << " ";
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (isFa[i])
            {
                num++;
                if (c[i].a > 0)
                {
                    double temp = (V * V - c[i].v * c[i].v) / (2 * c[i].a) + c[i].d;
                    l[num].a = upper_bound(posm + 1, posm + m + 1, temp) - posm;
                    l[num].b = m;
                }
                if (c[i].a == 0)
                {
                    l[num].a = upper_bound(posm + 1, posm + m + 1, c[i].a) - posm;
                    l[num].b = m;
                }
                else
                {
                    double temp = (V * V - c[i].v * c[i].v) / (2 * c[i].a) + c[i].d;
                    l[num].a = upper_bound(posm + 1, posm + m + 1, c[i].a) - posm;
                    l[num].b = lower_bound(posm + 1, posm + m + 1, temp) - posm;
                }
            }
        }
        sort(l + 1, l + num + 1, cmp2);
        int temp = l[1].b;
        int cnt = 1;
        for (int i = 1; i <= num; i++)
        {
            if (l[i].a > temp)
            {
                cnt++;
                temp = l[i].b;
            }
        }
        cout << m - cnt << endl;
    }
    return 0;
}

