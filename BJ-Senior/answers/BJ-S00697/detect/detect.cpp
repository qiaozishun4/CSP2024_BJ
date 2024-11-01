#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 1e5;
const int M = 1e5;
const double eps = 1e-6;

int n, m, len, maxv;
int d[N + 5], p[M + 5];
double v[N + 5], a[N + 5];

struct Range
{
    int l, r;
} ran[N + 5];
int tot;

struct BIT
{
private:
    int tree[M + 5], n;

    int lowbit(int x)
    {
        return x & -x;
    }

public:
    void update(int x)
    {
        while (x <= M)
        {
            ++tree[x];
            x += lowbit(x);
        }
    }

    int query(int x)
    {
        int res = 0;
        while (x)
        {
            res += tree[x];
            x -= lowbit(x);
        }
        return res;
    }

    void init()
    {
        for (int i = 1; i <= M; ++i) tree[i] = 0;
    }
} bit;

inline bool cmp1(Range a, Range b)
{
    return a.l > b.l;
}

inline bool cmp2(Range a, Range b)
{
    return a.l < b.l;
}

double calc(double s, double v, double a) // 计算该情况下的瞬时速度, 无法到达则返回 0.
{
    double temp = v * v + 2 * a * s;
    return temp < eps ? 0 : sqrt(temp);
}

bool check(int mid, int i)
{
    // if (i == 4 && p[mid] == 60882) cout << calc(p[mid] - d[i], v[i], a[i]) << endl;
    return calc(p[mid] - d[i], v[i], a[i]) > maxv + eps;
}

int find(int d)
{
    int l = 1;
    int r = m + 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (p[mid] >= d) r = mid;
        else l = mid + 1;
    }
    return l;
}

int lbound(int i) // 第 i 辆车第一次超速的测速仪, 没有则返回 m+1.
{
    int l = find(d[i]);
    int r = m + 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid, i)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int ubound(int i) // 第 i 辆车最后一次超速的测速仪, 没有则返回 0.
{
    int l = find(d[i]);
    int r = m;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid, i)) l = mid;
        else r = mid - 1;
    }
    return l == m + 1 ? 0 : l;
}

int solve()
{
    bit.init();
    sort(ran + 1, ran + tot + 1, cmp1);

    int temp = tot;
    for (int i = 1; i <= tot; ++i)
    {
        if (i <= tot && bit.query(ran[i].r))
        {
            ran[i].l = m + 1;
            --tot;
        }
        bit.update(ran[i].r);
    }

    int endpos = 0, res = 0;
    sort(ran + 1, ran + temp + 1, cmp2);

    for (int i = 1; i <= tot && ran[i].l <= m; ++i)
    {
        if (ran[i].l > endpos)
        {
            ++res;
            endpos = ran[i].r;
        }
    }
    return res;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> len >> maxv;
        for (int i = 1; i <= n; ++i) cin >> d[i] >> v[i] >> a[i];
        for (int i = 1; i <= m; ++i) cin >> p[i];

        for (int i = 1; i <= n; ++i)
        {
            int l = lbound(i), r = ubound(i);
            if (l <= r) ran[++tot] = {l, r};
        }

        cout << tot << " " << m - solve() << endl;
    }

    return 0;
}