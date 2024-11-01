#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
const int M = 2e3 + 10, N = 1e6 + 10;
#define int long long
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
int S, n, ans;
int a[N], f[M][M];
struct sgt
{
    struct node
    {
        int l, r, maxn, tag;
    }t[N * 4];
    void pushup(int p) {t[p].maxn = max(t[p << 1].maxn, t[p << 1 | 1].maxn);}
    void pushdown(int p)
    {
        if (t[p].tag)
        {
            t[p << 1].tag += t[p].tag;
            t[p << 1 | 1].tag += t[p].tag;
            t[p << 1].maxn += t[p].tag;
            t[p << 1 | 1].maxn += t[p].tag;
            t[p].tag = 0;
        }
    }
    void build(int p, int l, int r)
    {
        t[p].l = l, t[p].r = r, t[p].maxn = -0x3f3f3f3f, t[p].tag = 0;
        if (l == r) return ;
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
    }
    void modify(int p, int l, int r, int d)
    {
        if (t[p].l >= l && t[p].r <= r)
        {
            t[p].tag += d;
            t[p].maxn += d;
            // cout << t[p].l << ' ' << t[p].maxn << endl;
            return ;
        }
        pushdown(p);
        int mid = (t[p].l + t[p].r) >> 1;
        if (l <= mid) modify(p << 1, l, r, d);
        if (r > mid) modify(p << 1 | 1, l, r, d);
        pushup(p);
    }
    int query(int p, int l, int r)
    {
        if (l > r) return -0x3f3f3f3f;
        if (t[p].l >= l && t[p].r <= r) return t[p].maxn;
        pushdown(p);
        int mid = (t[p].l + t[p].r) >> 1, res = -0x3f3f3f3f;
        if (l <= mid) res = max(res, query(p << 1, l, r));
        if (r > mid) res = max(res, query(p << 1 | 1, l, r));
        return res;
    }
}T;
signed main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    S = read();
    while (S--)
    {
        n = read();
        for (int i = 1; i <= n; i++) a[i] = read();
        T.build(1, 0, 1e6);
        for (int i = 1; i <= n; i++)
        {
            int res = 0;
            res = max(res, max(T.query(1, 0, a[i] - 1), T.query(1, a[i] + 1, 1e6)));
            res = max(res, T.query(1, a[i], a[i]) + a[i]);
            T.modify(1, 0, 1e6, ((a[i] == a[i - 1]) ? a[i] : 0));
            T.modify(1, a[i - 1], a[i - 1], res - T.query(1, a[i - 1], a[i - 1]));
        }
        ans = T.query(1, 0, 1e6);
        printf("%lld\n", ans);
    }
    return 0;
}