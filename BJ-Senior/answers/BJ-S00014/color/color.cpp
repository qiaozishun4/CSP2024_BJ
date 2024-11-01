#include <bits/stdc++.h>
#define int long long
#define MAXN 1000005
using namespace std;
int T, n, a[MAXN], sum[MAXN], pre[MAXN], lst[MAXN], dp[MAXN], maxn[MAXN], ans;
signed main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%lld", &T);
    while (T--)
    {
        memset(a, 0, sizeof(a));
        memset(sum, 0, sizeof(sum));
        memset(pre, 0, sizeof(pre));
        memset(lst, 0, sizeof(lst));
        memset(dp, 0, sizeof(dp));
        memset(maxn, 0, sizeof(maxn));
        // memset * n;
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            sum[i] = sum[i - 1];
            if (a[i] == a[i - 1])
            {
                sum[i] += a[i];
            }
            pre[i] = lst[a[i]];
            lst[a[i]] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            if (pre[i] == 0)
            {
                maxn[i] = maxn[i - 1];
                continue;
            }
            int j = pre[i];
            if (j == i - 1)
            {
                dp[i] = maxn[i - 1] + a[i];
                maxn[i] = max(maxn[i - 1], dp[i]);
                continue;
            }
            dp[i] = maxn[j + 1] + a[i] + sum[i - 1] - sum[j + 1];
            // dp[i] = maxn[i - 1] + a[i];
            /*
            int pre2 = pre[j + 1];
            if (pre2 == 0)
            {
                dp[i] = maxn[j] + a[i] + sum[i - 1] - sum[j + 1];
            }
            else
            {

            }
            */
            maxn[i] = max(maxn[i - 1], dp[i]);
        }
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            // cout << dp[i] << " " << maxn[i] << "       \t";
            ans = max(ans, dp[i]);
        }
        // cout << endl;
        printf("%lld\n", ans);
    }
    return 0;
}
