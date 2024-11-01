#include  <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;

int n, a[N], now, last, ans;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++)
    {
        if (a[i] != a[i - 1])
        {
            now = max(now, i - 1);
            if (i - 1 - last > n - i + 1)
            {
                ans += n - i + 1;
                break;
            }
            now += i - 1 - last;
            ans = i - 1;
        }
    }
    printf("%d", n - ans);
    return 0;
}
