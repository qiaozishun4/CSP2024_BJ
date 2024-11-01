#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 2e5 + 5;

struct node
{
    int x, la;
} dp[N][2];

int a[N];

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        dp[2][1].la = a[1];
        if (a[2] == a[1]) dp[2][0].x = a[1];
        for (int i = 3; i <= n; i++)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
            if (a[i] == a[i - 1])
            {
                dp[i][0].x = dp[i - 1][0].x + a[i];
                dp[i][1].x = dp[i - 1][1].x + a[i];
            }
            int t = dp[i][1].x, t2 = dp[i][0].x;
            if (a[i] == dp[i][1].la)
            {
                t += a[i];
            }
            if (a[i] == dp[i][0].la)
            {
                t2 += a[i];
            }
            if (t >= dp[i][0].x)
            {
                dp[i][0].x = t;
                dp[i][0].la = a[i - 1];
            }
            if (t2 > dp[i][1].x)
            {
                dp[i][1].x = t2;
                dp[i][1].la = a[i - 1];
            }
        }
        printf("%d\n", max(dp[n][0].x, dp[n][1].x));
    }
    return 0;
}
