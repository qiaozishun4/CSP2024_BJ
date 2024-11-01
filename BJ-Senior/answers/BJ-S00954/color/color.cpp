#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int t, n;
long long ans;
int a[200010];

void dfs(int step, int lr, int lb, long long s)
{
    if (step > n)
    {
        ans = max(ans, s);
        return ;
    }
    // red
    int num = 0;
    if (lr == a[step])
        num = lr;
    dfs(step + 1, a[step], lb, s + num);
    num = 0;
    if (lb == a[step])
        num = lb;
    dfs(step + 1, lr, a[step], s + num);
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        ans = 0;
        dfs(1, 0, 0, 0);
        printf("%lld\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
