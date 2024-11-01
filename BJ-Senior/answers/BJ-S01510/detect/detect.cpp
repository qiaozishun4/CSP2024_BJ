#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1e5 + 5, M = 1e6 + 5;

int d[N], v[N], a[N], p[M], pos[N], p2[M], cs[N];

struct node
{
    int b, e;
}car[N];

bool cmp(node x, node y)
{
    if (x.e != y.e) return x.e < y.e;
    return x.b < y.b;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, l, v_max;
        scanf("%d%d%d%d", &n, &m, &l, &v_max);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &d[i], &v[i], &a[i]);
        }
        int max_pos = 0;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &pos[i]);
        }
        int cur = 1, cur2 = m;
        for (int i = 0; i <= l; i++)
        {
            if (i <= pos[cur])
            {
                p[i] = pos[cur];
            }
            else
            {
                cur++;
                p[i] = pos[cur];
            }
        }
        for (int i = l; i >= 0; i--)
        {
            if (i >= pos[cur2])
            {
                p2[i] = pos[cur2];
            }
            else
            {
                cur2--;
                p2[i] = pos[cur2];
            }
        }
        max_pos = pos[m];
        int cnt = 0, c = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0)
            {
                if (d[i] <= max_pos)
                {
                    if (v[i] > v_max)
                    {
                        cnt++;
                        cs[++c] = i;
                    }
                }
            }
            if (a[i] < 0)
            {
                if (d[i] <= max_pos)
                {
                    if (v_max * v_max < v[i] * v[i] + 2 * a[i] * (p[d[i]] - d[i]))
                    {
                        cnt++;
                        cs[++c] = i;
                    }
                }
            }
            if (a[i] > 0)
            {
                if (d[i] <= max_pos)
                {
                    if (v_max * v_max < v[i] * v[i] + 2 * a[i] * (max_pos - d[i]))
                    {
                        cnt++;
                        cs[++c] = i;
                    }
                }
            }
        }
        for (int i = 1; i <= c; i++)
        {
            if (a[cs[i]] < 0)
            {
                double t = 1.0 * (v_max - v[cs[i]]) / a[cs[i]];
                int s = d[cs[i]] + v[cs[i]] * t + 0.5 * a[cs[i]] * t * t;
                car[i].b = d[cs[i]];
                car[i].e = min(s, l);
            }
            else if (a[cs[i]] > 0)
            {
                double t = 1.0 * (v_max - v[cs[i]]) / a[cs[i]];
                int s = d[cs[i]] + v[cs[i]] * t + 0.5 * a[cs[i]] * t * t;
                car[i].b = s;
                car[i].e = l;
            }
            else
            {
                car[i].b = d[cs[i]];
                car[i].e = l;
            }
        }
        sort (car + 1, car + c + 1, cmp);
        int bc = 0, la = -1;
        for (int i = 1; i <= c; i++)
        {
            if (la >= car[i].b) continue;
            else
            {
                la = p2[car[i].e];
                bc++;
            }
        }
        printf("%d %d\n", cnt, m - bc);
    }
    return 0;
}
