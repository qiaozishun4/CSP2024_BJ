#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

const int NR = 2e5 + 10;
long long a[NR], ans = INT_MIN, n;

void dfs(int step, long long cnt, int la, int lb)
{
    if (step > n)
    {
        ans = max(ans, cnt);
        return;
    }
    if (la != -1 && a[step] == a[la]) dfs(step + 1, cnt + a[la], step, lb);
    else dfs(step + 1, cnt, step, lb);
    if (lb != -1 && a[step] == a[lb]) dfs(step + 1, cnt + a[lb], la, step);
    else dfs(step + 1, cnt, la, step);
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--)
    {
        ans = INT_MIN;
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", a + i);
        dfs(1, 0, -1, -1);
        printf("%lld\n", ans);
    }

    return 0;
}