#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define ll long long
const int N = 1e5 + 5, M = 25;

int t, n, m, l, flag[M], vis[M], minnum, ans;
ll V, d[N], v[N], a[N], p[N];

void check()
{
    memset(flag, 0, sizeof flag);
    for (int i = 1; i <= m; i++)
    {
        if (!vis[i]) continue;
        for (int j = 1; j <= n; j++)
        {
            if (d[j] <= p[i] && v[j] * v[j] + (ll)2 * a[j] * (p[i] - d[j]) > V * V)
            {
                flag[j] = 1;
            }
        }
    }
}

void dfs(int x, int nownum)
{
    if (nownum > minnum) return;
    if (x > m)
    {
        check();
        int tmp = 0;
        for (int i = 1; i <= n; i++)
        {
            if (flag[i]) tmp++;
        }
        if (tmp < ans) return;
        minnum = min(minnum, nownum);
        return;
    }
    vis[x + 1] = 0;
    dfs(x + 1, nownum);
    vis[x + 1] = 1;
    dfs(x + 1, nownum + 1);
}

void work1()
{
    minnum = 1e9;
    for (int i = 1; i <= m; i++) vis[i] = 1;
    check();
    for (int i = 1; i <= n; i++)
    {
        if (flag[i])
        {
            ans++;
        }
    }
    vis[1] = 0;
    dfs(1, 0);
    vis[1] = 1;
    dfs(1, 1);
    printf("%d %d\n", ans, m - minnum);
}

void work2()
{
    ll maxp = 0;
    for (int i = 1; i <= m; i++) maxp = max(maxp, p[i]);
    for (int i = 1; i <= n; i++)
    {
        if (d[i] <= maxp && v[i] > V)
        {
            ans++;
        }
    }
    if (ans) printf("%d %d\n", ans, m - 1);
    else printf("%d %d\n", ans, m);
}

void work3()
{
    ll maxp = 0;
    for (int i = 1; i <= m; i++) maxp = max(maxp, p[i]);
    for (int i = 1; i <= n; i++)
    {
        if (d[i] <= maxp && v[i] * v[i] + (ll)2 * a[i] * (maxp - d[i]) > V * V)
        {
            ans++;
        }
    }
    if (ans) printf("%d %d\n", ans, m - 1);
    else printf("%d %d\n", ans, m);
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
        ans = 0;
        scanf("%d%d%d%lld", &n, &m, &l, &V);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld%lld%lld", &d[i], &v[i], &a[i]);
        }
        for (int i = 1; i <= m; i++) scanf("%lld", &p[i]);
        if (n <= 20 && m <= 20) work1();
        else
        {
            if (a[1] == 0) work2();
            if (a[1] > 0) work3();
        }
    }
    return 0;
}
