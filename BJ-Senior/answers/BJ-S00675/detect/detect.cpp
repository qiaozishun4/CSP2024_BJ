#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
const ll INF = 0x3f3f3f3f, mod = 998244353;
const double eps = 1e-6;

int cases;
int n, m;
double L, V;
double d[N], a[N], v[N];
int p[N], fp[N], f[N][2], c[N], q[N];

struct Segment
{
    double l, r;
    bool opl, opr;
}s[N];

void mian()
{
    scanf("%d %d %lf %lf", &n, &m, &L, &V);
    for (int i = 1; i <= n; i ++) s[i].l = s[i].r = -1;
    for (int i = 1; i <= n; i ++)
    {
        scanf("%lf %lf %lf", &d[i], &v[i], &a[i]);
        if (a[i] == 0)
        {
            if (v[i] > V) 
            {
                s[i] = (Segment){d[i], L, 1, 1};
            }
        }
        else if (a[i] > 0)
        {
            if (v[i] > V)
            {
                s[i] = (Segment){d[i], L, 1, 1};
            }
            else
            {
                double tp = (double)(V * V - v[i] * v[i]) / (2 * a[i]) + d[i];
                s[i] = (Segment){tp, L, 0, 1};
            }
        }
        else
        {
            a[i] = -a[i];
            if (v[i] > V)
            {
                double tp = (double)(v[i] * v[i] - V * V) / (2 * a[i]) + d[i];
                if (tp > L) s[i] = (Segment){d[i], L, 1, 1};
                else s[i] = (Segment){d[i], tp, 1, 0};
            }
        } 
    }
    for (int i = 1; i <= m; i ++) scanf("%d", &p[i]);
    p[m + 1] = INF;

    int res = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (s[i].l > s[i].r) s[i].l = s[i].r = -1;
        else if (s[i].r - s[i].l < eps && (s[i].opl == 0 || s[i].opr == 0)) 
        {
            s[i].l = s[i].r = -1;
        } 

        if (s[i].l != -1)
        {
            double tmp = ceil(s[i].l);
            if (s[i].opl == 1) s[i].l = (int)tmp;
            else 
            {
                if (tmp - s[i].l < eps) s[i].l = (int)tmp + 1;
                else s[i].l = (int)tmp;
            }

            tmp = floor(s[i].r);
            if (s[i].opr == 1) s[i].r = (int)tmp;
            else
            {
                if (s[i].r - tmp < eps) s[i].r = (int)tmp - 1;
                else s[i].r = (int)tmp;
            }

            int pos = lower_bound(p + 1, p + m + 2, s[i].l) - p;
            int pos1 = upper_bound(p + 1, p + m + 2, s[i].r) - p;

            if (pos <= m && p[pos] <= s[i].r) 
            {
                res ++;
                s[i].l = pos, s[i].r = pos1 - 1;
            }
            else s[i].l = -1;
        }
    } 

    printf("%d ", res);

    for (int i = 1; i <= m; i ++) c[i] = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (s[i].l == -1) continue;
        c[(int)s[i].r] = max(c[(int)s[i].r], (int)s[i].l);
    }

    int pre = 0;
    f[0][1] = f[0][0] = 0;
    int hh = 0, tt = 0;
    q[0] = 0;
    for (int i = 1; i <= m; i ++)
    {
        pre = max(pre, c[i]);
        while (hh <= tt && q[hh] < pre) hh ++;

        f[i][1] = min(f[i - 1][0], f[i - 1][1]) + 1;
        if (hh <= tt) f[i][0] = f[hh][1];
        else f[i][0] = INF;

        while (hh <= tt && f[tt][1] > f[i][1]) tt --;
        q[++ tt] = i;
    }   
    printf("%d \n", m - min(f[m][0], f[m][1]));
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> cases;
    while (cases --) mian();
    return 0;
}