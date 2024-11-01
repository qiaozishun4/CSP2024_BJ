#include <bits/stdc++.h>
using namespace std;

struct range
{
    int l, r;
};

int d[100001], v[100001], a[100001], p[100001];
range b[100001];

bool cmp(range x, range y)
{
    if(x.r != y.r)
    {
        return x.r < y.r;
    }
    return x.l > y.l;
}

long double calc(int vv, int aa, long double tt)
{
    return (long long)vv * tt + (long double)0.5 * aa * tt * tt;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m, l, c;
        scanf("%d %d %d %d", &n, &m, &l, &c);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d %d %d", &d[i], &v[i], &a[i]);
        }
        for(int i = 1;i <= m;i++)
        {
            scanf("%d", &p[i]);
        }
        int cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            int lb = 1, rb = m, pos = 0;
            while(lb <= rb)
            {
                int mid = (lb + rb) >> 1;
                if(p[mid] >= d[i])
                {
                    rb = mid - 1;
                    pos = mid;
                }
                else
                {
                    lb = mid + 1;
                }
            }
            if(pos == 0)
            {
                continue;
            }
            if(a[i] > 0)
            {
                long double x = d[i] + max((long double)0, calc(v[i], a[i], ((long double)c - v[i]) / a[i]));
                lb = pos, rb = m;
                int pt = 0;
                while(lb <= rb)
                {
                    int mid = (lb + rb) >> 1;
                    if(p[mid] > x)
                    {
                        rb = mid - 1;
                        pt = mid;
                    }
                    else
                    {
                        lb = mid + 1;
                    }
                }
                if(pt != 0)
                {
                    cnt++;
                    b[cnt] = range{pt, m};
                }
            }
            else if(a[i] == 0)
            {
                if(v[i] > c)
                {
                    cnt++;
                    b[cnt] = range{pos, m};
                }
            }
            else
            {
                if(v[i] <= c)
                {
                    continue;
                }
                long double x = d[i] + calc(v[i], a[i], ((long double)c - v[i]) / a[i]);
                lb = pos, rb = m;
                int pt = 0;
                while(lb <= rb)
                {
                    int mid = (lb + rb) >> 1;
                    if(p[mid] < x)
                    {
                        lb = mid + 1;
                        pt = mid;
                    }
                    else
                    {
                        rb = mid - 1;
                    }
                }
                if(pt != 0)
                {
                    cnt++;
                    b[cnt] = range{pos, pt};
                }
            }
        }
        printf("%d ", cnt);
        sort(b + 1, b + cnt + 1, cmp);
        int res = 0, pos = 0;
        for(int i = 1;i <= cnt;i++)
        {
            if(pos < b[i].l)
            {
                res++;
                pos = b[i].r;
            }
        }
        printf("%d\n", m - res);
    }
    return 0;
}
