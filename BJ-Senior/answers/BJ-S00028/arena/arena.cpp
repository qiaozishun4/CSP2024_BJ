#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int dp[105][105][105], dp1[200005][15][15], maxn[200005], a[200005];
int main()
{
    freopen("color1.in", "r", stdin);
    //freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        memset(maxn, -0x3f, sizeof(maxn));

        //memset(dp1, 0, sizeof(dp1));
        if (n <= 100)
        {
            memset(dp, -0x3f, sizeof(dp));
            dp[0][0][0] = 0;
            m = 100;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= m; j++)
                {
                    dp[i][a[i]][j] = dp[i - 1][a[i]][j] + a[i];
                    //if (dp[i][a[i]][j] > 0) cout << 1 << " " << i << " "<< a[i] << " " << j << " " << dp[i][a[i]][j] << endl;
                }
                for (int j = 0; j <= m; j++)
                {
                    for (int k = 0; k <= m; k++)
                    {
                        dp[i][a[i]][k] = max(dp[i][a[i]][k], dp[i - 1][j][k]);
                    }
                    //cout << dp[i][]

                }
                for (int j = 0; j <= m; j++)
                {
                    dp[i][j][a[i]] = dp[a[i]][j][i - 1] + a[i];
                }
                for (int j = 0; j <= m; j++)
                {
                    for (int k = 0; k <= m; k++)
                        dp[i][k][a[i]] = max(dp[i][k][a[i]], dp[i - 1][k][j]);
                }
                //for (int j = 1; j <= m; j++)
                  //  for (int k = 1; k <= m; k++)
                     //   if (dp[i][j][k] >= 0) cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
            }
            int ans = -1;
            for (int j = 0; j <= m; j++)
                for (int k = 0; k <= m; k++)
                    ans = max(ans, dp[n][j][k]);
            cout << ans << endl;
        }
        else
        {
            memset(dp1, -0x3f, sizeof(dp1));
            dp1[0][0][0] = 0;
            m = 10;
            for (int i = 1; i <= n; i++)
            {

                for (int j = 0; j <= m; j++)
                {
                    dp1[i][a[i]][j] = dp1[i - 1][a[i]][j] + a[i];
                }
                for (int j = 0; j <= m; j++)
                {
                    for (int k = 0; k <= m; k++)
                        dp1[i][a[i]][k] = max(dp1[i][a[i]][k], dp1[i - 1][j][k]);
                }
                for (int j = 0; j <= m; j++)
                {
                    dp1[i][j][a[i]] = dp1[a[i]][j][i - 1] + a[i];
                }
                for (int j = 0; j <= m; j++)
                {
                    for (int k = 0; k <= m; k++)
                        dp1[i][k][a[i]] = max(dp1[i][k][a[i]], dp1[i - 1][k][j]);
                }
            }
            int ans = -1;
            for (int j = 0; j <= m; j++)
                for (int k = 0; k <= m; k++)
                    ans = max(ans, dp1[n][j][k]);
            cout << ans << endl;
        }
    }
    int n;
    cin >> n;

    return 0;
}
