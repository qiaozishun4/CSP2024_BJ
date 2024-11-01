#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, n, m, L, V, p[100005];
ll d[100005], v[100005], a[100005];
ll speed(ll i, ll s)
{
    if (s < d[i] || s > L) return 0;
    else return v[i] * v[i] + 2 * a[i] * (s - d[i]);
}
bool r[100005];
ll ans1, ans2;
bitset<100005> bsr, c[100005];
bool used[35];
void dfs(int now)
{
    if (now == m + 1)
    {
        ll cnt = 0;
        bitset<100005> mi;
        for (int i = 1; i <= m; i++)
            if (used[i])
            {
                mi |= c[i];
                cnt++;
            }
        if (mi == bsr)
            ans2 = max(ans2, m - cnt);
        return ;
    }
    used[now] = 1;
    dfs(now + 1);
    used[now] = 0;
    dfs(now + 1);
}
namespace p3
{
    void main()
    {
        for (int i = 1; i <= n; i++)
            if (d[i] <= p[m] && v[i] > V)
                ans1++;
        ans2 = m - 1;
        if (ans1 == 0) ans2++;
        printf("%lld %lld\n", ans1, ans2);
    }
};
namespace p5
{
    void main()
    {
        for (int i = 1; i <= n; i++)
            if (d[i] <= p[m] && sqrt(v[i] * v[i] + 2 * a[i] * (p[m] - d[i])) > V)
                ans1++;
        ans2 = m - 1;
        if (ans1 == 0) ans2++;
        printf("%lld %lld\n", ans1, ans2);
    }
};
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld%lld%lld%lld", &n, &m, &L, &V);
        memset(r, 0, sizeof(r));
        for (int i = 1; i <= m; i++) c[i] = 0;
        bsr = 0;
        ans1 = ans2 = 0;
        bool bada = 0, badb = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld%lld%lld", &d[i], &v[i], &a[i]);
            if (a[i] != 0)
                bada = 1;
            if (a[i] <= 0)
                badb = 1;
        }
        for (int i = 1; i <= m; i++)
            scanf("%lld", &p[i]);
        if (!bada)
        {
            p3::main();
            continue;
        }
        if (!badb)
        {
            p5::main();
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                if (sqrt(speed(i, p[j])) > V)
                {
                    r[i] = 1;
                    bsr[i] = 1;
                    c[j][i] = 1;
                }
        }
        for (int i = 1; i <= n; i++)
            ans1 += r[i];
        ans2 = 0;
        dfs(1);
        printf("%lld %lld\n", ans1, ans2);
    }
    return 0;
}
