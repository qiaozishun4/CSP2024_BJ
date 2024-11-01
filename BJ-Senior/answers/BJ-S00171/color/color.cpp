#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 2e5 + 5;

int t, n, a[N], ans;

void dfs(int x, int c, int red, int blue)
{
    if (x > n)
    {
        ans = max(ans, c);
        return;
    }
    if (red == a[x]) dfs(x + 1, c + a[x], a[x], blue);
    else dfs(x + 1, c, a[x], blue);
    if (blue == a[x]) dfs(x + 1, c + a[x], red, a[x]);
    else dfs(x + 1, c, red, a[x]);
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        dfs(1, 0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
