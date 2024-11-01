#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define N (100000 + 10)
#define eps (double)1e-8

struct car_t
{
    int d;
    int v, a;
};

struct line_t
{
    int l, r;
    friend bool operator<(line_t a, line_t b) {
        return a.r < b.r;
    }
};

int n, m, L;
double V;
car_t car[N];
int pos[N];
line_t a[N];

bool check(int v0, int a, int s)
{
    return sqrt((double)v0 * v0 + 2.0 * a * s) - V > eps;
}

int find1(int i, int t)
{
    int l = t, r = m - 1;
    while (r - l > 10)
    {
        int mid = (l + r) / 2;
        if (check(car[i].v, car[i].a, pos[mid] - car[i].d))
            r = mid;
        else
            l = mid;
    }

    while (l <= r)
    {
        if (check(car[i].v, car[i].a, pos[l] - car[i].d))
            return l;
        l++;
    }
    return -1;
}

int find2(int i, int t)
{
    int l = t, r = m - 1;
    while (r - l > 10)
    {
        int mid = (l + r) / 2;
        if (check(car[i].v, car[i].a, pos[mid] - car[i].d))
            l = mid;
        else
            r = mid;
    }

    while (r >= l)
    {
        if (check(car[i].v, car[i].a, pos[r] - car[i].d))
            return r;
        r--;
    }
    return -1;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%lf", &n, &m, &L, &V);
        for (int i = 0; i < n; i++)
            scanf("%d%d%d", &car[i].d, &car[i].v, &car[i].a);
        for (int i = 0; i < m; i++)
            scanf("%d", &pos[i]);

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int t = lower_bound(pos, pos + m, car[i].d) - pos;
            a[i].l = a[i].r = -1;
            if (t == m)
                continue;
            double v;
            if (car[i].a == 0)
            {
                v = car[i].v;
                if (v - V > eps)
                    cnt++, a[i].l = t, a[i].r = m - 1;
            }
            else if (car[i].a > 0)
            {
                v = sqrt((double)car[i].v * car[i].v + 2.0 * car[i].a * (pos[m - 1] - car[i].d));
                if (v - V > eps)
                {
                    cnt++, a[i].r = m - 1;
                    a[i].l = find1(i, t);
                }
            }
            else
            {
                v = sqrt((double)car[i].v * car[i].v + 2.0 * car[i].a * (pos[t] - car[i].d));
                if (v - V > eps)
                {
                    cnt++, a[i].l = t;
                    a[i].r = find2(i, t);
                }
            }
        }

        printf("%d ", cnt);
        if (cnt == 0)
        {
            printf("%d\n", m);
            continue;
        }

        cnt = 0;
        sort(a, a + n);
        int t = -1;
        for (int i = 0; i < n; i++)
            if (a[i].l == -1 && a[i].r == -1)
                continue;
            else
            {
                if (t < a[i].l)
                    cnt++, t = a[i].r;
            }
        printf("%d\n", m - cnt);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}