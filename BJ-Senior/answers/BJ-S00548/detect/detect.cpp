#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int L[N], R[N], cnti, f[N], pos[N], c[N];
int n, m, Len, V, d[N], v[N], a[N], p[N], T;
typedef long long ll;

void add(int x, int y)
{
    x = m + 2 - x;
    for(; x <= m + 2; x += x & -x) c[x] = min(c[x], y);
}

int ask(int x)
{
    x = m + 2 - x;
    int res = INF;
    for(; x; x -= x & -x) res = min(res, c[x]);
    return res;
}

void calc()
{
    m--;
    //scanf("%d%d", &m, &cnti);

    //for(int i = 1; i <= cnti; i++) scanf("%d%d", &L[i], &R[i]);

    //for(int i = 1; i <= cnti; i++) printf("%d %d\n", L[i], R[i]); puts("");

    int lmx = 0;
    for(int i = 1; i <= cnti; i++) lmx = max(lmx, L[i]);
    for(int i = 1; i <= cnti; i++) pos[R[i] + 1] = max(pos[R[i] + 1], L[i]);
    for(int i = 1; i <= m; i++) pos[i] = max(pos[i], pos[i - 1]);
    memset(c, 0x3f, sizeof(c)); add(0, 0);
    for(int i = 1; i <= m; i++)
    {
        f[i] = ask(pos[i]) + 1; add(i, f[i]); //cout << f[i] << endl;
    }
    int ans = INF;
    for(int i = lmx; i <= m; i++) ans = min(ans, f[i]);
    printf("%d %d\n", cnti, m - ans);
    for(int i = 1; i <= m + 1; i++) pos[i] = 0;
    return;
}

int valid(int i, int j) // i n j m
{
    if(a[i] < 0)
    {
        if((ll)v[i] * v[i] < 2ll * (ll)a[i] * (ll)(p[j] - d[i])) return 1;
    }
    ll v1 = (ll)v[i] * v[i] + 2ll * (ll)a[i] * (ll)(p[j] - d[i]);
    return v1 <= (ll)V * V;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &T);
    while(T--)
    {
        cnti = 0;
        scanf("%d%d%d%d", &n, &m, &Len, &V);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &d[i], &v[i], &a[i]);
        }
        for(int i = 1; i <= m; i++) scanf("%d", &p[i]);
        p[++m] = Len + 1;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] == 0)
            {
                if(v[i] > V)
                {
                    int x = lower_bound(p + 1, p + m + 1, d[i]) - p;
                    if(x < m)
                    {
                        cnti++;
                        L[cnti] = x, R[cnti] = m - 1;
                    }
                }
            }
            else if(a[i] > 0)
            {
                int l = lower_bound(p + 1, p + m + 1, d[i]) - p, r = m - 1, posr = r;
                if(l < m && !valid(i, r))
                {
                    while(l < r)
                    {
                        int mid = l + r >> 1;
                        if(!valid(i, mid)) r = mid;
                        else l = mid + 1;
                    }
                    cnti++;
                    L[cnti] = l, R[cnti] = posr;
                }
            }
            else
            {
                int l = lower_bound(p + 1, p + m + 1, d[i]) - p, posl = l, r = m - 1;
                if(l < m && !valid(i, l))
                {
                    while(l < r)
                    {
                        int mid = l + r + 1 >> 1;
                        if(!valid(i, mid)) l = mid;
                        else r = mid - 1;
                    }
                    cnti++;
                    L[cnti] = posl, R[cnti] = r;
                }
            }
        }
        calc();
    }

    return 0;
}
