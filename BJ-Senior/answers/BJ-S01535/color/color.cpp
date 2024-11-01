#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int NR = 1e6 + 5;
const int MR = 2e5 + 5;

int n;
int a[NR];
int b[MR];
int lft[MR];
long long dp[MR];//1 to i,max score,number i 's color is k
int dp2[MR][2];//opposite  i to n,max score,number i 's color is k
long long sum[MR];

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    int T;
    cin >> T;
    while (T --)
    {
        memset(lft, 0, sizeof(lft));
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));

        cin >> n;
        memset(b, 0, sizeof(b));
        for (int i = 1;i <= n;i ++)
        {
            cin >> a[i];
            if (b[a[i]] != 0)
                lft[i] = b[a[i]];
            b[a[i]] = i;

            sum[i] = sum[i - 1];
            if (a[i] == a[i - 1])
            {
                if (a[i - 1] == a[i - 2])
                    sum[i] = max(sum[i], sum[i - 1] + a[i]);
                else
                    sum[i] = max(sum[i], sum[i - 2] + a[i]);
            }
        }

        for (int i = 2;i <= n;i ++)
        {
            dp[i] = dp[i - 1];
            if (lft[i] != 0)
            {
                int t = 0;
                if (a[lft[i] + 1] == a[lft[i] - 1])
                    t = a[lft[i] + 1];
                dp[i] = max(dp[i], dp[lft[i - 1]] + a[i] + t + sum[i] - max(sum[lft[i]], sum[lft[i] + 1]));
                t = 0;
                if (a[lft[i] + 1] == a[lft[i] - 2])
                    t = a[lft[i] + 1];
                dp[i] = max(dp[i], dp[lft[i]] + t + a[i] + sum[i] - max(sum[lft[i]], sum[lft[i] + 1]));
            }
        }

        cout << dp[n] << '\n';
    }
    return 0;
}
