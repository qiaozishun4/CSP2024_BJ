#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

const int N = 1e5 + 10;

int p[N], f[N], sz = 0;
int n, m, L, V;
struct car
{
    int d, v, a;
    int l, r;
}c[N];
bool cmp(car x, car y)
{
    return x.r < y.r;
}
void detect()
{
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(c[i].a > 0)
        {
            if(c[i].v > V)
            {
                c[i].l = c[i].d, c[i].r = L;
                continue;
            }
            double x = 1.0 * (V * V - c[i].v * c[i].v) / (2 * c[i].a) + (double)c[i].d;
            if(x > L) continue;
            c[i].l = floor(x) + 1, c[i].r = L;
        }
        else if(c[i].a == 0)
        {
            if(c[i].v <= V) continue;
            c[i].l = c[i].d, c[i].r = L;
        }
        else
        {
            if(c[i].v < V) continue;
            double x = 1.0 * (V * V - c[i].v * c[i].v) / (2 * c[i].a) + (double)c[i].d;
            c[i].l = c[i].d, c[i].r = min(L, (int)ceil(x) - 1);
        }
    }
}
int solve()
{
    if(sz == 0) return 0;
    int cnt = 1, lst = upper_bound(p + 1, p + m + 1, c[f[1]].r) - p - 1;
    for(int j = 2, i = f[j]; j <= sz; j++, i = f[j])
    {
        int pos = upper_bound(p + 1, p + m + 1, c[i].r) - p - 1;
        if(p[pos] > c[i].r) pos--;
        if(c[i].l > p[lst])
            lst = pos, cnt++;
    }
    return cnt;
}
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(p, 0, sizeof p);
        memset(f, 0, sizeof f);
        sz = 0;
        for(int i = 0; i < N; i++)
            c[i] = {0, 0, 0, 0, 0};
        scanf("%d%d%d%d",&n, &m, &L, &V);
        for(int i = 1; i <= n; i++)
            scanf("%d%d%d", &c[i].d, &c[i].v, &c[i].a);
        for(int i = 1; i <= m; i++)
            scanf("%d", p + i);
        sort(p + 1, p + m + 1);
        detect();
        sort(c + 1, c + n + 1, cmp);
        for(int i = 1; i <= n; i++)
        {
            if(!c[i].l && !c[i].r) continue;
            int pos = upper_bound(p + 1, p + m + 1, c[i].r) - p - 1;
            if(p[pos] >= c[i].l && c[i].r >= p[pos]) f[++sz] = i;
        }
        printf("%d ", sz);
        printf("%d\n", m - solve());
    }
    return 0;
}
