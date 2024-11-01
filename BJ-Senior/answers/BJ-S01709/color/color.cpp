#include<bits/stdc++.h>
using namespace std;
constexpr int N = 205;
int T, n, dp[N][N][2], a[200005];
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        if(n < N)
        {
            memset(dp, 0, sizeof dp);
            for(int i = 1; i <= n; ++i)
            {
                for(int j = 0; j < i; ++j)
                {
                    for(int k = 0; k < 2; ++k)
                    {
                        for(int p = 0; p < j; ++p)
                        {
                            dp[i][j][k] = max(dp[i][j][k], dp[j][p][k ^ 1] + (a[p] == a[j + 1]) * a[j + 1]);
                        }
                        for(int p = j + 1; p < i; ++p)
                            dp[i][j][k] += (a[p] == a[p + 1]) * a[p];
                    }
                }
            }
            int ans = 0;
            for(int i = 1; i < n; ++i)
                ans = max(ans, max(dp[n][i][0], dp[n][i][1]));
            cout << ans << '\n';
        }
    }
    return 0;
}
