#include <bits/stdc++.h>
using namespace std;

int a[1000001], cnt[1000001], pre[1000001];
long long dp[2000001], calc[2000001];

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1;i <= n;i++)
        {
            scanf("%d", &a[i]);
            pre[i] = cnt[a[i]];
            cnt[a[i]] = i;
            calc[i] = calc[i - 1];
            if(a[i] == a[i - 1])
            {
                calc[i] += a[i];
            }
        }
        dp[1] = 0;
        for(int i = 2;i <= n;i++)
        {
            dp[i] = dp[i - 1];
            int j = i;
            long long cnt = 0;
            while(pre[j] > 0)
            {
                cnt += a[j] + calc[j - 1] - calc[pre[j]];
                dp[i] = max(dp[i], dp[pre[j]] + cnt);
                if(j == pre[j] + 1)
                {
                    break;
                }
                j = pre[j] + 1;
            }
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}
