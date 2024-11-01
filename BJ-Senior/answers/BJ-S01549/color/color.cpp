#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;
const ll INF = 1e18;
int T, n;
int a[N];
int p[N], pos[N], ql[N], qr[N];
bool cmp(int x, int y)
{
    return a[x] < a[y];
}

ll mx[N * 4], lz[N * 4];
void up(int now)
{
    mx[now] = max(mx[now << 1], mx[now << 1 | 1]);
}
void upd(int now, ll x)
{
    mx[now] += x;
    lz[now] += x;
}
void down(int now)
{
    upd(now << 1, lz[now]);
    upd(now << 1 | 1, lz[now]);
    lz[now] = 0;
}
void build(int now, int l, int r)
{
    lz[now] = 0;
    mx[now] = -INF;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(now << 1, l, mid);
    build(now << 1 | 1, mid + 1, r);
}
void add(int now, int l, int r, int ql, int qr, ll v)
{
    if (ql <= l && qr >= r)
    {
        upd(now, v);
        return;
    }
    if (ql > r || qr < l) return;
    int mid = (l + r) >> 1;
    down(now);
    add(now << 1, l, mid, ql, qr, v);
    add(now << 1 | 1, mid + 1, r, ql, qr, v);
    up(now);
}
void mdf(int now, int l, int r, int p, ll v)
{
    if (l == r)
    {
        lz[now] = 0;
        mx[now] = v;
        return;
    }
    int mid = (l + r) >> 1;
    down(now);
    if (p <= mid) mdf(now << 1, l, mid, p, v);
    else mdf(now << 1 | 1, mid + 1, r, p, v);
    up(now);
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    //15:52
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            p[i] = i;
        }
        sort(p + 1, p + 1 + n, cmp);
        for (int i = 1; i <= n; i++)
            pos[p[i]] = i;
        for (int i = 1; i <= n; )
        {
            int j = i + 1;
            while (j <= n && a[p[j]] == a[p[i]]) j++;
            for (int k = i; k < j; k++)
            {
                ql[k] = i;
                qr[k] = j - 1;
            }
            i = j;
        }
        build(1, 0, n);
        mdf(1, 0, n, 0, 0);
        for (int i = 2; i <= n; i++)
        {
            add(1, 0, n, ql[pos[i]], qr[pos[i]], a[i]);
            ll t = mx[1];
            add(1, 0, n, ql[pos[i]], qr[pos[i]], -a[i]);
            if (a[i] == a[i - 1]) add(1, 0, n, 0, n, a[i]);
            mdf(1, 0, n, pos[i - 1], t);
        }
        printf("%lld\n", mx[1]);
    }
    return 0;
}
