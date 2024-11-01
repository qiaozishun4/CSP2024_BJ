#include <iostream>
#include <cstdio>
#define int long long

using namespace std;

const int N = 2e5 + 5, N1 = 2e3 + 5, V = 1e6 + 5, INF = 1e9;
int T, n, a[N], f[N1][N1], lst[V], mx, g[N], h[N], ans, f1[N][20];

void calc()
{
    int lst1 = 0, lst0 = 0;
    g[0] = 0;
    for(int i = 1;i <= n;i++)
    {
        if(h[i] == 0)
        {
            g[i] = g[lst0] + (a[i] == a[lst0] ? a[i] : 0);
            lst0 = i;
        }
        else
        {
            g[i] = g[lst1] + (a[i] == a[lst1] ? a[i] : 0);
            lst1 = i;
        }
    }
    ans = max(ans, g[lst0] + g[lst1]);
}

void dfs(int x)
{
    if(x > n)
    {
        calc();
        return ;
    }
    h[x] = 1;
    dfs(x+1);
    h[x] = 0;
    dfs(x+1);
    return ;
}

void work1()
{
    for(int i = 0;i <= n;i++)
        for(int j = 1;j <= mx;j++)  f1[i][j] = -INF;
    for(int i = 0;i <= n;i++)   f1[i][0] = 0;
    h[0] = 0;
    for(int i = 1;i <= n;i++)
    {
        h[i] = h[i-1] + (a[i]==a[i-1]?a[i]:0);
        if(lst[a[i]] != 0 && lst[a[i]] == i-1)
        {
            f1[i][a[i-1]] = max(f1[i][a[i-1]], 0ll);
            for(int j = 0;j <= mx;j++)
                f1[i][j] = max(f1[i][j], f1[i-1][j] + a[i]);
            lst[a[i]] = i;
            continue;
        }
        f1[i][a[i-1]] = max(f1[i][a[i-1]], h[i-1]);
        for(int j = 0;j <= mx;j++)
            f1[i][j] = max(f1[i][j], f1[i-1][j]);
        if(lst[a[i]] == 0)
        {
            lst[a[i]] = i;
            continue;
        }
        g[i-1] = 0;
        int lef = a[i-1];
        for(int j = i-2;j > lst[a[i]];j--)
        {
            g[j] = g[j+1] + (a[j] == a[j+1] ? 1 : 0) * a[j];
            lef = a[j];
        }
        for(int j = 0;j <= mx;j++)
            f1[i][a[i-1]] = max(f1[i][a[i-1]], f1[lst[a[i]]][j] + a[i] + g[lst[a[i]]+1] + (j==lef?j:0));
        for(int j = 0;j <= mx;j++)  ans = max(ans, f1[i][j]);
        lst[a[i]] = i;
    }
    /*for(int i = 1;i <= n;i++)
    {
        for(int j = 0;j <= mx;j++)  printf("%lld ", f1[i][j]);
        puts("");
    }*/
    printf("%lld\n", ans);
}

void work2()
{
    for(int i = 0;i <= n;i++)
        for(int j = 1;j <= mx;j++)  f[i][j] = -INF;
    for(int i = 0;i <= n;i++)   f[i][0] = 0;
    h[0] = 0;
    for(int i = 1;i <= n;i++)
    {
        h[i] = h[i-1] + (a[i]==a[i-1]?a[i]:0);
        if(lst[a[i]] != 0 && lst[a[i]] == i-1)
        {
            f[i][a[i-1]] = max(f[i][a[i-1]], 0ll);
            for(int j = 0;j <= mx;j++)
                f[i][j] = max(f[i][j], f[i-1][j] + a[i]);
            lst[a[i]] = i;
            continue;
        }
        f[i][a[i-1]] = max(f[i][a[i-1]], h[i-1]);
        for(int j = 0;j <= mx;j++)
            f[i][j] = max(f[i][j], f[i-1][j]);
        if(lst[a[i]] == 0)
        {
            lst[a[i]] = i;
            continue;
        }
        g[i-1] = 0;
        int lef = a[i-1];
        for(int j = i-2;j > lst[a[i]];j--)
        {
            g[j] = g[j+1] + (a[j] == a[j+1] ? 1 : 0) * a[j];
            lef = a[j];
        }
        for(int j = 0;j <= mx;j++)
            f[i][a[i-1]] = max(f[i][a[i-1]], f[lst[a[i]]][j] + a[i] + g[lst[a[i]]+1] + (j==lef?j:0));
        for(int j = 0;j <= mx;j++)  ans = max(ans, f[i][j]);
        lst[a[i]] = i;
    }
    /*for(int i = 1;i <= n;i++)
    {
        for(int j = 0;j <= mx;j++)  printf("%lld ", f[i][j]);
        puts("");
    }*/
    printf("%lld\n", ans);
}

void solve()
{
    ans = 0, mx = 0;
    scanf("%lld", &n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%lld", &a[i]);
        lst[a[i]] = 0;
        mx = max(mx, a[i]);
    }
    if(n <= 15)
    {
        dfs(1);
        printf("%d\n", ans);
        return ;
    }
    if(1ll * n * mx >= 10000000ll)
    {
        puts("-1");
        return ;
    }
    if(mx <= 10)    work1();
    else work2();
}

signed main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%lld", &T);
    while(T--)  solve();
    return 0;
}
