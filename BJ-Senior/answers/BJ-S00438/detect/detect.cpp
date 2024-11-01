#include <bits/stdc++.h>
#define int long long
using namespace std;

const int NR = 1e5;
int T, n, m, L, V;
int tot, cnt, ans;
struct node
{
    int d, v, a;
}h[NR + 7];
struct elem
{
    int l, r, a;
}g[NR + 7];
int p[NR + 7], f[NR + 7];

bool check1(int u, int v)
{
    if(g[v].a == 0) return p[u] >= g[v].l;
    else if(g[v].a > 0) return p[u] * 2 * g[v].a >= g[v].l;
    else return p[u] * 2 * g[v].a <= g[v].l;
}

bool check2(int u, int v)
{
    if(g[v].a == 0) return p[u] <= g[v].r;
    else if(g[v].a > 0) return p[u] * 2 * g[v].a <= g[v].r;
    else return p[u] * 2 * g[v].a >= g[v].r;
}

bool cmp(elem u, elem v)
{
    if(u.l == 0) return false;
    if(v.l == 0) return true;
    if(u.a == 0 || v.a == 0)
    {
        if(u.a == 0 && v.a == 0) return u.l > v.l;
        else if(u.a == 0)
        {
            if(v.a < 0) return u.l * v.a * 2 < v.l;
            else return u.l * v.a * 2 > v.l;
        }
        else
        {
            if(u.a < 0) return u.l < v.l * 2 * u.a;
            else return u.l > v.l * 2 * u.a;
        }
    }
    if(u.a * v.a < 0) return u.l * v.a * 2 < v.l * u.a * 2;
    else return u.l * v.a * 2 > v.l * u.a * 2;
}

int find1(int pos)
{
    int l = 1, r = m, val = m + 1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(check1(mid, pos)) val = mid, r = mid - 1;
        else l = mid + 1;
    }
    return val;
}

int find2(int pos)
{
    int l = 1, r = m, val = 0;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(check2(mid, pos)) val = mid, l = mid + 1;
        else r = mid - 1;
    }
    return val;
}

signed main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        tot = 0, ans = 0, cnt = 0;
        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld%lld%lld", &h[i].d, &h[i].v, &h[i].a);
            if(h[i].a == 0)
            {
                if(h[i].v <= V) continue;
                tot++;
                g[tot].l = h[i].d, g[tot].r = L, g[tot].a = 0;
            }
            else if(h[i].a < 0)
            {
                if(h[i].v <= V) continue;
                tot++;
                g[tot].l = g[tot].r = h[i].d * 2 * h[i].a;
                g[tot].r += V * V - h[i].v * h[i].v - 1;
                if(g[tot].r < 2 * h[i].a * L) g[tot].r = 2 * h[i].a * L;
                g[tot].a = h[i].a;
                if(g[tot].l < g[tot].r) g[tot].r = g[tot].l;
            }
            else
            {
                int pos = V * V - h[i].v * h[i].v;
                if(pos < 0) pos = -1;
                if(pos + h[i].d * (2 * h[i].a) >= L * (2 * h[i].a) && h[i].v <= V) continue;
                tot++;
                g[tot].l = pos + 1 + h[i].d * (2 * h[i].a);
                g[tot].r = 2 * h[i].a * L;
                g[tot].a = h[i].a;
                if(g[tot].l > g[tot].r) g[tot].l = g[tot].r;
            }
        }
        for(int i = 1; i <= m; i++)
            scanf("%lld", &p[i]);
        sort(g + 1, g + tot + 1, cmp);
        for(int i = 1; i <= tot; i++)
        {
            int posl = find1(i), posr = find2(i);
            if(posl > posr) continue;
            ans++;
            if(cnt != 0 && f[cnt] <= posr) continue;
            f[++cnt] = posl;
        }
        cout << ans << " " << m - cnt << endl;
    }
    return 0;
}
