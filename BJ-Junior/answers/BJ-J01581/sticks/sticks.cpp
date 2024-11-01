#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int t, n, dp[100005];
int cnt[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

signed main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
    {
        memset(dp, 127, sizeof(dp));
        cin >> n;
        for(int i = 1; i <= 9; i++)
        {
            dp[cnt[i]] = min(dp[cnt[i]], i);
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= 9; j++)
            {
                if(i - cnt[j] <= 0 || dp[i - cnt[j]] == dp[0])
                {
                    continue;
                }
                dp[i] = min(dp[i], dp[i - cnt[j]] * 10 + j);
            }
        }
        // for(int i = 0; i <= n; i++)
        // {
        //     cout << "dp[" << i << "] = " << dp[i] << endl;
        // }
        if(dp[n] != dp[0])
        {
            cout << dp[n] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}