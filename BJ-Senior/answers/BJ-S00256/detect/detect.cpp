#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;

struct Car
{
    int d, v, a;
}c[100010];
int p[100010];

struct Seg
{
    int l, r;
}s[100010];
int tot, vis[100010];

bool cmp(Seg x, Seg y)
{
    if (x.r != y.r) return x.r < y.r;
    return x.l < y.l;
}

signed main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    scanf("%lld", &T);
    while (T--)
    {
        tot = 0;
        memset(vis, 0, sizeof(vis));
        int n, m, L, V;
        scanf("%lld %lld %lld %lld", &n, &m, &L, &V);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld %lld %lld", &c[i].d, &c[i].v, &c[i].a);
        }
        int pmax = -1;
        for (int i = 1; i <= m; i++)
        {
            scanf("%lld", &p[i]);
            pmax = max(pmax, p[i]);
        }
        sort(p + 1, p + m + 1);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (c[i].a > 0)
            {
                if (pmax - c[i].d < 0) continue;
                if (2 * c[i].a * (pmax - c[i].d) > (V * V - c[i].v * c[i].v)) cnt++;
                for (int j = 1; j <= m; j++)
                {
                    if (p[j] - c[i].d < 0) continue;
                    if (2 * c[i].a * (p[j] - c[i].d) > (V * V - c[i].v * c[i].v))
                    {
                        s[++tot].l = j;
                        s[tot].r = m;
                        break;
                    }
                }
            }
            if (c[i].a == 0)
            {
                if (pmax - c[i].d < 0) continue;
                if (c[i].v > V)
                {
                    for (int j = 1; j <= m; j++)
                    {
                        if (p[j] - c[i].d < 0) continue;
                        s[++tot].l = j;
                        s[tot].r = m;
                        break;
                    }
                    cnt++;
                }
            }
            if (c[i].a < 0)
            {
                if (pmax - c[i].d < 0 || c[i].v <= V) continue;
                int tar = V * V - c[i].v * c[i].v;
                for (int j = 1; j <= m; j++)
                {
                    if (p[j] - c[i].d < 0) continue;
                    if (2 * c[i].a * (p[j] - c[i].d) > tar)
                    {
                        cnt++;
                        s[++tot].l = j;
                        break;
                    }
                }
                for (int j = m; j >= 1; j--)
                {
                    if (p[j] - c[i].d < 0) break;
                    if (2 * c[i].a * (p[j] - c[i].d) > tar)
                    {
                        s[tot].r = j;
                        break;
                    }
                }
            }
        }
        printf("%lld ", cnt);
        // for (int i = 1; i <= tot; i++) cout << s[i].l << " " << s[i].r << endl;
        sort(s + 1, s + tot + 1, cmp);
        int ans = 0;
        for (int i = 1; i <= tot; i++)
        {
            if (vis[i]) continue;
            ans++;
            for (int j = i; j <= tot; j++)
            {
                if (s[i].r >= s[j].l) vis[j] = 1;
            }
        }
        printf("%lld\n", m - ans);
    }
    return 0;
}
