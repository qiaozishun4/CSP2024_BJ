#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5;
const int MX = 1e6 + 1;

int t, n;
int a[N], p[MX], pre[N], sum[N];
long long dp[N];

int main(void)
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    cin >> t;
    while (t--)
    {
        for (int i = 0; i < MX; i++)
        {
            p[i] = -1;
        }

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            pre[i] = p[a[i]];
            p[a[i]] = i;
        }

        for (int i = 1; i < n; i++)
        {
            sum[i] = sum[i - 1];
            if (a[i] == a[i - 1])
            {
                sum[i] += a[i - 1];
            }

            if (pre[i] == -1)
            {
                dp[i] = dp[i - 1];
            }
            else if (pre[i] == i - 1)
            {
                dp[i] = dp[i - 1] + a[i];
            }
            else
            {
                dp[i] = max(dp[i - 1], dp[pre[i] + 1] + a[i] + sum[i] - sum[pre[i]]);
            }
        }
        cout << dp[n - 1] << endl;
    }

    return 0;
}