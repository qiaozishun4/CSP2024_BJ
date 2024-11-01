#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
const ll INF = 1e13;

int n, T, a[N], b[N], totb;
struct SegmentTree{
    int l, r;
    ll mx, add;
}tr[N << 2];

void pushup(int p)
{
    tr[p].mx = max(tr[p << 1].mx, tr[p << 1 | 1].mx);
}

void pushadd(int p, ll add)
{
    tr[p].add += add, tr[p].mx += add;
}

void pushdown(int p)
{
    if(tr[p].add)
    {
        pushadd(p << 1, tr[p].add), pushadd(p << 1 | 1, tr[p].add);
        tr[p].add = 0;
    }
}

void change(int p, int x, ll y)
{
    if(tr[p].l == tr[p].r)
    {
        tr[p].mx = max(tr[p].mx, y);
        return;
    }
    pushdown(p);
    int mid = tr[p].l + tr[p].r >> 1;
    if(x <= mid) change(p << 1, x, y);
    else change(p << 1 | 1, x, y);
    pushup(p);
}

void change2(int p, int x, int y, ll add)
{
    if(x > y) return;
    if(x <= tr[p].l && tr[p].r <= y)
    {
        pushadd(p, add);
        return;
    }
    pushdown(p);
    int mid = tr[p].l + tr[p].r >> 1;
    if(x <= mid) change2(p << 1, x, y, add);
    if(y > mid) change2(p << 1 | 1, x, y, add);
    pushup(p);
}

ll query(int p, int x, int y)
{
    if(x > y) return -INF;
    if(x <= tr[p].l && tr[p].r <= y)
    {
        return tr[p].mx;
    }
    pushdown(p);
    int mid = tr[p].l + tr[p].r >> 1; ll res = -INF;
    if(x <= mid) res = max(res, query(p << 1, x, y));
    if(y > mid) res = max(res, query(p << 1 | 1, x, y));
    return res;
}

void build(int p, int l, int r)
{
    tr[p].l = l, tr[p].r = r, tr[p].mx = -INF, tr[p].add = 0;
    if(l == r) return;
    int mid = l + r >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
}

int valb(int x)
{
    return lower_bound(b + 1, b + totb + 1, x) - b;
}
/*
void bf()
{
    memset(f, 0xcf, sizeof(f)); f[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        f[a[i - 1]] = max(f[a[i - 1]], f[a[i]] + b[a[i]]);
        for(int j = 0; j <= totb; j++) if(j != a[i]) f[a[i - 1]] = max(f[a[i - 1]], f[j]);
        if(a[i] == a[i - 1])
        {
            for(int j = 0; j <= totb; j++) if(j != a[i]) f[j] += b[a[i]];
        }
        for(int j = 0; j <= totb; j++) cout << f[j] << " "; cout << endl;
    }
    ll ans = 0; for(int i = 0; i <= totb; i++) ans = max(ans, f[i]);
    ("%lld\n", ans);
    return;
}*/

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n; totb = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i]; b[++totb] = a[i];
        }
        sort(b + 1, b + totb + 1); totb = unique(b + 1, b + totb + 1) - b - 1;
        for(int i = 1; i <= n; i++) a[i] = valb(a[i]);
        //bf(); return 0;
        build(1, 0, totb); change(1, 0, 0);
        for(int i = 1; i <= n; i++)
        {
            change(1, a[i - 1], query(1, a[i], a[i]) + b[a[i]]); change(1, a[i - 1], max(query(1, 0, a[i] - 1), query(1, a[i] + 1, totb)));
            if(a[i] == a[i - 1])
            {
                change2(1, 0, a[i] - 1, b[a[i]]), change2(1, a[i] + 1, totb, b[a[i]]);
            }
        }
        cout << tr[1].mx << endl;
    }
    return 0;
}
