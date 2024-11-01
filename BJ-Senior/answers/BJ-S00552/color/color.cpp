#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
const int maxa = 2010;

int t, n;
int a[maxn], pre[maxn];
int now[maxa];
int score[maxn];
int dp[maxn][2];

int main ()
{
    freopen ("color.in", "r", stdin);
    freopen ("color.out", "w", stdout);
    cin >> t;
    while (t --)
    {
        memset (pre, 0, sizeof (pre));
        memset (now, 0, sizeof (now));
        memset (score, 0, sizeof (score));
        memset (dp, 0, sizeof (dp));
        cin >> n;
        for (int i = 1; i <= n; i ++)
        {
            cin >> a[i];
            if (now[a[i]] != 0)
            {
                pre[i] = now[a[i]];
            }
            now[a[i]] = i;
        }
        for (int i = 1; i <= n; i ++)
        {
            for (int j = pre[i] + 1; j < i; j ++)
            {
                if (pre[j] > pre[i] && pre[j] == j - 1) score[i] += a[j];
            }
        }
        for (int i = 1; i <= n; i ++)
        {
            int tmp = 0;
            dp[i][0] = dp[i][1] = max (dp[i - 1][0], dp[i - 1][1]);
            if (pre[i] == i - 1 && i != 1)
            {
                dp[i][0] = max (dp[i][0], dp[i - 1][0] + a[i]);
                dp[i][1] = max (dp[i][1], dp[i - 1][1] + a[i]);
                continue;
            }
            for (int j = i, k = 0; pre[j]; j = pre[j] + 1, k ++)
            {
                tmp += a[j] + score[j];
                dp[i][0] = max (dp[i][0], dp[pre[j]][k % 2] + tmp);
                dp[i][1] = max (dp[i][1], dp[pre[j]][(k + 1) % 2] + tmp);
            }
        }
        cout << max (dp[n][0], dp[n][1]) << endl;

    }
    return 0;
}
